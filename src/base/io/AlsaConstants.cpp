// Copyright (c) Signal Estimator authors
// Licensed under MIT

#include <alsa/asoundlib.h>

#include <cstdio>

#define print(name) printf("#define %s %d\n", #name, name)

int main() {
    printf("// Copyright (c) Signal Estimator authors\n"
           "// Licensed under MIT\n"
           "\n"
           "// Generated by AlsaConstants.cpp. DO NOT EDIT!\n"
           "\n"
           "#pragma once\n"
           "\n");

    print(SND_PCM_FORMAT_UNKNOWN);

    print(SND_PCM_FORMAT_S8);
    print(SND_PCM_FORMAT_U8);

    print(SND_PCM_FORMAT_S16_BE);
    print(SND_PCM_FORMAT_S16_LE);
    print(SND_PCM_FORMAT_U16_BE);
    print(SND_PCM_FORMAT_U16_LE);

    print(SND_PCM_FORMAT_S18_3BE);
    print(SND_PCM_FORMAT_S18_3LE);
    print(SND_PCM_FORMAT_U18_3BE);
    print(SND_PCM_FORMAT_U18_3LE);

    print(SND_PCM_FORMAT_S20_3BE);
    print(SND_PCM_FORMAT_S20_3LE);
    print(SND_PCM_FORMAT_U20_3BE);
    print(SND_PCM_FORMAT_U20_3LE);

    print(SND_PCM_FORMAT_S20_BE);
    print(SND_PCM_FORMAT_S20_LE);
    print(SND_PCM_FORMAT_U20_BE);
    print(SND_PCM_FORMAT_U20_LE);

    print(SND_PCM_FORMAT_S24_3BE);
    print(SND_PCM_FORMAT_S24_3LE);
    print(SND_PCM_FORMAT_U24_3BE);
    print(SND_PCM_FORMAT_U24_3LE);

    print(SND_PCM_FORMAT_S24_BE);
    print(SND_PCM_FORMAT_S24_LE);
    print(SND_PCM_FORMAT_U24_BE);
    print(SND_PCM_FORMAT_U24_LE);

    print(SND_PCM_FORMAT_S32_BE);
    print(SND_PCM_FORMAT_S32_LE);
    print(SND_PCM_FORMAT_U32_BE);
    print(SND_PCM_FORMAT_U32_LE);

    print(SND_PCM_FORMAT_FLOAT_BE);
    print(SND_PCM_FORMAT_FLOAT_LE);

    print(SND_PCM_FORMAT_FLOAT64_BE);
    print(SND_PCM_FORMAT_FLOAT64_LE);

    return 0;
}
