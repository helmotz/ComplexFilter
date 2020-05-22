import scipy.signal as signal
import matplotlib.pyplot as plt
import numpy as np


def quantize_taps(taps):
    result = []
    for t in taps:
        q = int(t * pow(2, 10))
        result.append(q)

    return np.array(result)


def generate_taps_file(fname, taps):
    with open(fname, "w+") as f:
        lines = []

        lines.append("#include \"ComplexFilter.h\"")
        lines.append("")

        n_taps = len(taps)

        i_taps = quantize_taps(np.real(taps))
        q_taps = quantize_taps(np.imag(taps))

        lines.append("ComplexFilter::TapType taps_i[]={")
        for i in range(n_taps):
            if i < n_taps-1:
                lines.append("    {},".format(i_taps[i]))
            else:
                lines.append("    {}".format(i_taps[i]))
        lines.append("};")
        lines.append("")
        lines.append("ComplexFilter::TapType taps_q[]={")
        for i in range(n_taps):
            if i < n_taps-1:
                lines.append("    {},".format(q_taps[i]))
            else:
                lines.append("    {}".format(q_taps[i]))
        lines.append("};")
        lines.append("")

        for l in lines:
            print(l, file=f)


if __name__ == "__main__":
    taps0 = signal.firwin(512, [0.06, 0.6], window='hamming', pass_zero='bandpass')
    taps1 = signal.hilbert(taps0)

    #plt.figure()
    #plt.plot(np.real(taps1))
    #plt.plot(np.imag(taps1))
    #plt.show()

    generate_taps_file(fname='../vscode/src/taps.cpp', taps=taps1)
