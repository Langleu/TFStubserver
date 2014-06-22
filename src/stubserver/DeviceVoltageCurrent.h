/*
 * DeviceVoltageCurrent.h
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
#ifndef DEVICEVOLTAGECURRENT_H_
#define DEVICEVOLTAGECURRENT_H_

#include "DeviceFunctions.h"

namespace stubserver {

/**
 * A device sub-functionality that handles getCurrent() and getVoltage() requests
 * and handles periodical callbacks for current / voltage changes.
 */
class DeviceVoltageCurrent : public DeviceFunctions
{
    const uint8_t funcGetVoltage;
    const uint8_t funcGetCurrent;

    ValueProvider *volts;
    ValueProvider *amps;

    BasicCallback voltsChangedCb;
    BasicCallback ampsChangedCb;
    BasicCallback powerChangedCb;
    bool hasPowerSensor;


public:
    DeviceVoltageCurrent();
    DeviceVoltageCurrent(DeviceFunctions* _other, uint8_t _funcGetVoltage, uint8_t _funcGetCurrent);
    DeviceVoltageCurrent(uint8_t _funcGetVoltage, uint8_t _funcGetCurrent,
                         uint8_t _funcSetCallbackVoltage, uint8_t _funcSetCallbackCurrent,
                         uint8_t _funcCallbackVoltage, uint8_t _funcCallbackCurrent);
    ~DeviceVoltageCurrent();

    /**
     * Changes the value provider: must be non-null, the ownership is taken
     * into this object and released when the object is destroyed.
     */
    void setVoltageValueProvider(ValueProvider *vp);
    void setCurrentValueProvider(ValueProvider *vp);

    bool consumeCommand(uint64_t relativeTimeMs, IOPacket &p, bool &stateChanged);
    void checkCallbacks(uint64_t relativeTimeMs, unsigned int uid, BrickStack *brickStack, bool &stateChanged);
};

} /* namespace stubserver */

#endif /* DEVICEVOLTAGECURRENT_H_ */
