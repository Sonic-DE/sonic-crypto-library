/*
 * Copyright (C) 2026 SonicDE
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#pragma once

#include "qca_support.h"

#include <QStringEncoder>
#include <QStringView>

#include <limits>

namespace QCA::Internal {
inline SecureArray encodeSecure(QStringView input, QStringEncoder &encoder)
{
    const qsizetype required = encoder.requiredSpace(input.size());
    if (required < 0 || required > std::numeric_limits<int>::max()) {
        return {};
    }

    SecureArray output(static_cast<int>(required));
    char *const begin = output.data();
    char *const end   = encoder.appendToBuffer(begin, input);
    output.resize(static_cast<int>(end - begin));
    return output;
}
}
