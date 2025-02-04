/*
 * DevicePiezoSpeaker.h
 *
 * Copyright (C) 2013 Holger Grosenick
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef DEVICEPIEZOSPEAKER_H_
#define DEVICEPIEZOSPEAKER_H_

#include <utils/SoundPlayback.h>

#include "DeviceFunctions.h"

namespace stubserver {

using utils::SoundPlayback;

/**
 * This simulated devices makes some sound via ALSA API.
 */
class DevicePiezoSpeaker : public DeviceFunctions
{
    // these are to handle the callback when sound finishes
    bool     sendCallback;
    int8_t   callbackFunctionId;
    uint64_t callbackTime;

    // frequency & duration of the last buffer
    unsigned frequency;
    unsigned duration;
    SoundPlayback::WavBuffer wavBuffer;
    SoundPlayback player;

public:
    DevicePiezoSpeaker();
    virtual ~DevicePiezoSpeaker();

    DECLARE_OWN_DEVICE_CALLBACKS
};

} /* namespace stubserver */

#endif /* DEVICEPIEZOSPEAKER_H_ */
