#include "ComplexFilter.h"

ComplexFilter::TapType taps_i[]={
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    1,
    0,
    1,
    0,
    1,
    0,
    0,
    -1,
    0,
    -1,
    0,
    -1,
    0,
    -1,
    -1,
    0,
    -1,
    0,
    -1,
    0,
    -1,
    0,
    -1,
    1,
    0,
    1,
    0,
    1,
    0,
    1,
    1,
    1,
    1,
    0,
    2,
    0,
    2,
    0,
    1,
    -1,
    1,
    -2,
    0,
    -2,
    0,
    -2,
    -1,
    -2,
    -2,
    -1,
    -2,
    0,
    -2,
    0,
    -2,
    2,
    -2,
    2,
    -1,
    3,
    0,
    3,
    1,
    2,
    2,
    2,
    3,
    0,
    3,
    0,
    3,
    -2,
    3,
    -3,
    1,
    -4,
    0,
    -4,
    -1,
    -4,
    -3,
    -3,
    -4,
    -1,
    -5,
    0,
    -5,
    2,
    -4,
    4,
    -3,
    5,
    -1,
    6,
    1,
    6,
    3,
    5,
    5,
    3,
    7,
    0,
    7,
    -2,
    7,
    -5,
    5,
    -7,
    2,
    -9,
    0,
    -9,
    -4,
    -8,
    -7,
    -5,
    -10,
    -2,
    -11,
    2,
    -11,
    6,
    -9,
    11,
    -6,
    14,
    0,
    15,
    5,
    14,
    11,
    11,
    16,
    6,
    20,
    -1,
    22,
    -10,
    21,
    -20,
    15,
    -29,
    6,
    -36,
    -7,
    -40,
    -25,
    -39,
    -49,
    -30,
    -81,
    -6,
    -130,
    56,
    -269,
    587,
    587,
    -269,
    56,
    -130,
    -6,
    -81,
    -30,
    -49,
    -39,
    -25,
    -40,
    -7,
    -36,
    6,
    -29,
    15,
    -20,
    21,
    -10,
    22,
    -1,
    20,
    6,
    16,
    11,
    11,
    14,
    5,
    15,
    0,
    14,
    -6,
    11,
    -9,
    6,
    -11,
    2,
    -11,
    -2,
    -10,
    -5,
    -7,
    -8,
    -4,
    -9,
    0,
    -9,
    2,
    -7,
    5,
    -5,
    7,
    -2,
    7,
    0,
    7,
    3,
    5,
    5,
    3,
    6,
    1,
    6,
    -1,
    5,
    -3,
    4,
    -4,
    2,
    -5,
    0,
    -5,
    -1,
    -4,
    -3,
    -3,
    -4,
    -1,
    -4,
    0,
    -4,
    1,
    -3,
    3,
    -2,
    3,
    0,
    3,
    0,
    3,
    2,
    2,
    2,
    1,
    3,
    0,
    3,
    -1,
    2,
    -2,
    2,
    -2,
    0,
    -2,
    0,
    -2,
    -1,
    -2,
    -2,
    -1,
    -2,
    0,
    -2,
    0,
    -2,
    1,
    -1,
    1,
    0,
    2,
    0,
    2,
    0,
    1,
    1,
    1,
    1,
    0,
    1,
    0,
    1,
    0,
    1,
    -1,
    0,
    -1,
    0,
    -1,
    0,
    -1,
    0,
    -1,
    -1,
    0,
    -1,
    0,
    -1,
    0,
    -1,
    0,
    0,
    1,
    0,
    1,
    0,
    1,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0
};

ComplexFilter::TapType taps_q[]={
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    1,
    0,
    1,
    0,
    1,
    0,
    0,
    1,
    0,
    1,
    0,
    1,
    0,
    1,
    -1,
    0,
    -1,
    0,
    -1,
    0,
    -1,
    0,
    -1,
    -1,
    0,
    -1,
    0,
    -1,
    0,
    -1,
    1,
    -1,
    1,
    0,
    2,
    0,
    2,
    0,
    1,
    1,
    1,
    2,
    0,
    2,
    0,
    2,
    -1,
    2,
    -2,
    1,
    -2,
    0,
    -2,
    0,
    -2,
    -2,
    -2,
    -2,
    -1,
    -3,
    0,
    -3,
    1,
    -2,
    2,
    -2,
    3,
    0,
    3,
    0,
    3,
    2,
    3,
    3,
    1,
    4,
    0,
    4,
    -1,
    4,
    -3,
    3,
    -4,
    1,
    -5,
    0,
    -5,
    -2,
    -4,
    -4,
    -3,
    -5,
    -1,
    -6,
    1,
    -6,
    3,
    -5,
    5,
    -3,
    7,
    0,
    7,
    2,
    7,
    5,
    5,
    7,
    2,
    9,
    0,
    9,
    -4,
    8,
    -7,
    5,
    -10,
    2,
    -11,
    -2,
    -11,
    -6,
    -9,
    -11,
    -6,
    -14,
    0,
    -15,
    5,
    -14,
    11,
    -11,
    16,
    -6,
    20,
    1,
    22,
    10,
    21,
    20,
    15,
    29,
    6,
    36,
    -7,
    40,
    -25,
    39,
    -49,
    30,
    -81,
    6,
    -130,
    -56,
    -269,
    -587,
    587,
    269,
    56,
    130,
    -6,
    81,
    -30,
    49,
    -39,
    25,
    -40,
    7,
    -36,
    -6,
    -29,
    -15,
    -20,
    -21,
    -10,
    -22,
    -1,
    -20,
    6,
    -16,
    11,
    -11,
    14,
    -5,
    15,
    0,
    14,
    6,
    11,
    9,
    6,
    11,
    2,
    11,
    -2,
    10,
    -5,
    7,
    -8,
    4,
    -9,
    0,
    -9,
    -2,
    -7,
    -5,
    -5,
    -7,
    -2,
    -7,
    0,
    -7,
    3,
    -5,
    5,
    -3,
    6,
    -1,
    6,
    1,
    5,
    3,
    4,
    4,
    2,
    5,
    0,
    5,
    -1,
    4,
    -3,
    3,
    -4,
    1,
    -4,
    0,
    -4,
    -1,
    -3,
    -3,
    -2,
    -3,
    0,
    -3,
    0,
    -3,
    2,
    -2,
    2,
    -1,
    3,
    0,
    3,
    1,
    2,
    2,
    2,
    2,
    0,
    2,
    0,
    2,
    -1,
    2,
    -2,
    1,
    -2,
    0,
    -2,
    0,
    -2,
    -1,
    -1,
    -1,
    0,
    -2,
    0,
    -2,
    0,
    -1,
    1,
    -1,
    1,
    0,
    1,
    0,
    1,
    0,
    1,
    1,
    0,
    1,
    0,
    1,
    0,
    1,
    0,
    1,
    -1,
    0,
    -1,
    0,
    -1,
    0,
    -1,
    0,
    0,
    -1,
    0,
    -1,
    0,
    -1,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0
};

