/* ***********************************************************
 * This file was automatically generated on 2018-10-05.      *
 *                                                           *
 * C/C++ Bindings Version 2.1.22                             *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/

#ifndef BRICKLET_MOTION_DETECTOR_V2_H
#define BRICKLET_MOTION_DETECTOR_V2_H

#include "ip_connection.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup BrickletMotionDetectorV2 Motion Detector Bricklet 2.0
 */

/**
 * \ingroup BrickletMotionDetectorV2
 *
 * Passive infrared (PIR) motion sensor, 12m range
 */
typedef Device MotionDetectorV2;

/**
 * \ingroup BrickletMotionDetectorV2
 */
#define MOTION_DETECTOR_V2_FUNCTION_GET_MOTION_DETECTED 1

/**
 * \ingroup BrickletMotionDetectorV2
 */
#define MOTION_DETECTOR_V2_FUNCTION_SET_SENSITIVITY 2

/**
 * \ingroup BrickletMotionDetectorV2
 */
#define MOTION_DETECTOR_V2_FUNCTION_GET_SENSITIVITY 3

/**
 * \ingroup BrickletMotionDetectorV2
 */
#define MOTION_DETECTOR_V2_FUNCTION_SET_INDICATOR 4

/**
 * \ingroup BrickletMotionDetectorV2
 */
#define MOTION_DETECTOR_V2_FUNCTION_GET_INDICATOR 5

/**
 * \ingroup BrickletMotionDetectorV2
 */
#define MOTION_DETECTOR_V2_FUNCTION_GET_SPITFP_ERROR_COUNT 234

/**
 * \ingroup BrickletMotionDetectorV2
 */
#define MOTION_DETECTOR_V2_FUNCTION_SET_BOOTLOADER_MODE 235

/**
 * \ingroup BrickletMotionDetectorV2
 */
#define MOTION_DETECTOR_V2_FUNCTION_GET_BOOTLOADER_MODE 236

/**
 * \ingroup BrickletMotionDetectorV2
 */
#define MOTION_DETECTOR_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER 237

/**
 * \ingroup BrickletMotionDetectorV2
 */
#define MOTION_DETECTOR_V2_FUNCTION_WRITE_FIRMWARE 238

/**
 * \ingroup BrickletMotionDetectorV2
 */
#define MOTION_DETECTOR_V2_FUNCTION_SET_STATUS_LED_CONFIG 239

/**
 * \ingroup BrickletMotionDetectorV2
 */
#define MOTION_DETECTOR_V2_FUNCTION_GET_STATUS_LED_CONFIG 240

/**
 * \ingroup BrickletMotionDetectorV2
 */
#define MOTION_DETECTOR_V2_FUNCTION_GET_CHIP_TEMPERATURE 242

/**
 * \ingroup BrickletMotionDetectorV2
 */
#define MOTION_DETECTOR_V2_FUNCTION_RESET 243

/**
 * \ingroup BrickletMotionDetectorV2
 */
#define MOTION_DETECTOR_V2_FUNCTION_WRITE_UID 248

/**
 * \ingroup BrickletMotionDetectorV2
 */
#define MOTION_DETECTOR_V2_FUNCTION_READ_UID 249

/**
 * \ingroup BrickletMotionDetectorV2
 */
#define MOTION_DETECTOR_V2_FUNCTION_GET_IDENTITY 255

/**
 * \ingroup BrickletMotionDetectorV2
 *
 * Signature: \code void callback(void *user_data) \endcode
 * 
 * This callback is called after a motion was detected.
 */
#define MOTION_DETECTOR_V2_CALLBACK_MOTION_DETECTED 6

/**
 * \ingroup BrickletMotionDetectorV2
 *
 * Signature: \code void callback(void *user_data) \endcode
 * 
 * This callback is called when the detection cycle ended. When this
 * callback is called, a new motion can be detected again after approximately 2
 * seconds.
 */
#define MOTION_DETECTOR_V2_CALLBACK_DETECTION_CYCLE_ENDED 7


/**
 * \ingroup BrickletMotionDetectorV2
 */
#define MOTION_DETECTOR_V2_MOTION_NOT_DETECTED 0

/**
 * \ingroup BrickletMotionDetectorV2
 */
#define MOTION_DETECTOR_V2_MOTION_DETECTED 1

/**
 * \ingroup BrickletMotionDetectorV2
 */
#define MOTION_DETECTOR_V2_BOOTLOADER_MODE_BOOTLOADER 0

/**
 * \ingroup BrickletMotionDetectorV2
 */
#define MOTION_DETECTOR_V2_BOOTLOADER_MODE_FIRMWARE 1

/**
 * \ingroup BrickletMotionDetectorV2
 */
#define MOTION_DETECTOR_V2_BOOTLOADER_MODE_BOOTLOADER_WAIT_FOR_REBOOT 2

/**
 * \ingroup BrickletMotionDetectorV2
 */
#define MOTION_DETECTOR_V2_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_REBOOT 3

/**
 * \ingroup BrickletMotionDetectorV2
 */
#define MOTION_DETECTOR_V2_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_ERASE_AND_REBOOT 4

/**
 * \ingroup BrickletMotionDetectorV2
 */
#define MOTION_DETECTOR_V2_BOOTLOADER_STATUS_OK 0

/**
 * \ingroup BrickletMotionDetectorV2
 */
#define MOTION_DETECTOR_V2_BOOTLOADER_STATUS_INVALID_MODE 1

/**
 * \ingroup BrickletMotionDetectorV2
 */
#define MOTION_DETECTOR_V2_BOOTLOADER_STATUS_NO_CHANGE 2

/**
 * \ingroup BrickletMotionDetectorV2
 */
#define MOTION_DETECTOR_V2_BOOTLOADER_STATUS_ENTRY_FUNCTION_NOT_PRESENT 3

/**
 * \ingroup BrickletMotionDetectorV2
 */
#define MOTION_DETECTOR_V2_BOOTLOADER_STATUS_DEVICE_IDENTIFIER_INCORRECT 4

/**
 * \ingroup BrickletMotionDetectorV2
 */
#define MOTION_DETECTOR_V2_BOOTLOADER_STATUS_CRC_MISMATCH 5

/**
 * \ingroup BrickletMotionDetectorV2
 */
#define MOTION_DETECTOR_V2_STATUS_LED_CONFIG_OFF 0

/**
 * \ingroup BrickletMotionDetectorV2
 */
#define MOTION_DETECTOR_V2_STATUS_LED_CONFIG_ON 1

/**
 * \ingroup BrickletMotionDetectorV2
 */
#define MOTION_DETECTOR_V2_STATUS_LED_CONFIG_SHOW_HEARTBEAT 2

/**
 * \ingroup BrickletMotionDetectorV2
 */
#define MOTION_DETECTOR_V2_STATUS_LED_CONFIG_SHOW_STATUS 3

/**
 * \ingroup BrickletMotionDetectorV2
 *
 * This constant is used to identify a Motion Detector Bricklet 2.0.
 *
 * The {@link motion_detector_v2_get_identity} function and the
 * {@link IPCON_CALLBACK_ENUMERATE} callback of the IP Connection have a
 * \c device_identifier parameter to specify the Brick's or Bricklet's type.
 */
#define MOTION_DETECTOR_V2_DEVICE_IDENTIFIER 292

/**
 * \ingroup BrickletMotionDetectorV2
 *
 * This constant represents the display name of a Motion Detector Bricklet 2.0.
 */
#define MOTION_DETECTOR_V2_DEVICE_DISPLAY_NAME "Motion Detector Bricklet 2.0"

/**
 * \ingroup BrickletMotionDetectorV2
 *
 * Creates the device object \c motion_detector_v2 with the unique device ID \c uid and adds
 * it to the IPConnection \c ipcon.
 */
void motion_detector_v2_create(MotionDetectorV2 *motion_detector_v2, const char *uid, IPConnection *ipcon);

/**
 * \ingroup BrickletMotionDetectorV2
 *
 * Removes the device object \c motion_detector_v2 from its IPConnection and destroys it.
 * The device object cannot be used anymore afterwards.
 */
void motion_detector_v2_destroy(MotionDetectorV2 *motion_detector_v2);

/**
 * \ingroup BrickletMotionDetectorV2
 *
 * Returns the response expected flag for the function specified by the
 * \c function_id parameter. It is *true* if the function is expected to
 * send a response, *false* otherwise.
 *
 * For getter functions this is enabled by default and cannot be disabled,
 * because those functions will always send a response. For callback
 * configuration functions it is enabled by default too, but can be disabled
 * via the motion_detector_v2_set_response_expected function. For setter functions it is
 * disabled by default and can be enabled.
 *
 * Enabling the response expected flag for a setter function allows to
 * detect timeouts and other error conditions calls of this setter as well.
 * The device will then send a response for this purpose. If this flag is
 * disabled for a setter function then no response is send and errors are
 * silently ignored, because they cannot be detected.
 */
int motion_detector_v2_get_response_expected(MotionDetectorV2 *motion_detector_v2, uint8_t function_id, bool *ret_response_expected);

/**
 * \ingroup BrickletMotionDetectorV2
 *
 * Changes the response expected flag of the function specified by the
 * \c function_id parameter. This flag can only be changed for setter
 * (default value: *false*) and callback configuration functions
 * (default value: *true*). For getter functions it is always enabled.
 *
 * Enabling the response expected flag for a setter function allows to detect
 * timeouts and other error conditions calls of this setter as well. The device
 * will then send a response for this purpose. If this flag is disabled for a
 * setter function then no response is send and errors are silently ignored,
 * because they cannot be detected.
 */
int motion_detector_v2_set_response_expected(MotionDetectorV2 *motion_detector_v2, uint8_t function_id, bool response_expected);

/**
 * \ingroup BrickletMotionDetectorV2
 *
 * Changes the response expected flag for all setter and callback configuration
 * functions of this device at once.
 */
int motion_detector_v2_set_response_expected_all(MotionDetectorV2 *motion_detector_v2, bool response_expected);

/**
 * \ingroup BrickletMotionDetectorV2
 *
 * Registers the given \c function with the given \c callback_id. The
 * \c user_data will be passed as the last parameter to the \c function.
 */
void motion_detector_v2_register_callback(MotionDetectorV2 *motion_detector_v2, int16_t callback_id, void *function, void *user_data);

/**
 * \ingroup BrickletMotionDetectorV2
 *
 * Returns the API version (major, minor, release) of the bindings for this
 * device.
 */
int motion_detector_v2_get_api_version(MotionDetectorV2 *motion_detector_v2, uint8_t ret_api_version[3]);

/**
 * \ingroup BrickletMotionDetectorV2
 *
 * Returns 1 if a motion was detected. How long this returns 1 after a motion
 * was detected can be adjusted with one of the small potentiometers on the
 * Motion Detector Bricklet, see :ref:`here
 * <motion_detector_bricklet_sensitivity_delay_block_time>`.
 * 
 * There is also a blue LED on the Bricklet that is on as long as the Bricklet is
 * in the "motion detected" state.
 */
int motion_detector_v2_get_motion_detected(MotionDetectorV2 *motion_detector_v2, uint8_t *ret_motion);

/**
 * \ingroup BrickletMotionDetectorV2
 *
 * Sets the sensitivity of the PIR sensor. The range is 0-100. At full
 * sensitivity (100), the Bricklet can detect motion in a range of approximately 12m.
 * 
 * The actual range depends on many things in the environment (e.g. reflections) and the
 * size of the object to be detected. While a big person might be detected in a range
 * of 10m a cat may only be detected at 2m distance with the same setting.
 * 
 * So you will have to find a good sensitivity for your application by trial and error.
 * 
 * The default value is 50.
 */
int motion_detector_v2_set_sensitivity(MotionDetectorV2 *motion_detector_v2, uint8_t sensitivity);

/**
 * \ingroup BrickletMotionDetectorV2
 *
 * Returns the sensitivity as set by {@link motion_detector_v2_set_sensitivity}.
 */
int motion_detector_v2_get_sensitivity(MotionDetectorV2 *motion_detector_v2, uint8_t *ret_sensitivity);

/**
 * \ingroup BrickletMotionDetectorV2
 *
 * Sets the blue backlight of the fresnel lens. The backlight consists of
 * three LEDs. The brightness of each LED can be controlled with a 8-bit value
 * (0-255). A value of 0 turns the LED off and a value of 255 turns the LED
 * to full brightness.
 * 
 * The default value is 0, 0, 0.
 */
int motion_detector_v2_set_indicator(MotionDetectorV2 *motion_detector_v2, uint8_t top_left, uint8_t top_right, uint8_t bottom);

/**
 * \ingroup BrickletMotionDetectorV2
 *
 * Returns the indicator configuration as set by {@link motion_detector_v2_set_indicator}.
 */
int motion_detector_v2_get_indicator(MotionDetectorV2 *motion_detector_v2, uint8_t *ret_top_left, uint8_t *ret_top_right, uint8_t *ret_bottom);

/**
 * \ingroup BrickletMotionDetectorV2
 *
 * Returns the error count for the communication between Brick and Bricklet.
 * 
 * The errors are divided into
 * 
 * * ACK checksum errors,
 * * message checksum errors,
 * * framing errors and
 * * overflow errors.
 * 
 * The errors counts are for errors that occur on the Bricklet side. All
 * Bricks have a similar function that returns the errors on the Brick side.
 */
int motion_detector_v2_get_spitfp_error_count(MotionDetectorV2 *motion_detector_v2, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow);

/**
 * \ingroup BrickletMotionDetectorV2
 *
 * Sets the bootloader mode and returns the status after the requested
 * mode change was instigated.
 * 
 * You can change from bootloader mode to firmware mode and vice versa. A change
 * from bootloader mode to firmware mode will only take place if the entry function,
 * device identifier and CRC are present and correct.
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
int motion_detector_v2_set_bootloader_mode(MotionDetectorV2 *motion_detector_v2, uint8_t mode, uint8_t *ret_status);

/**
 * \ingroup BrickletMotionDetectorV2
 *
 * Returns the current bootloader mode, see {@link motion_detector_v2_set_bootloader_mode}.
 */
int motion_detector_v2_get_bootloader_mode(MotionDetectorV2 *motion_detector_v2, uint8_t *ret_mode);

/**
 * \ingroup BrickletMotionDetectorV2
 *
 * Sets the firmware pointer for {@link motion_detector_v2_write_firmware}. The pointer has
 * to be increased by chunks of size 64. The data is written to flash
 * every 4 chunks (which equals to one page of size 256).
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
int motion_detector_v2_set_write_firmware_pointer(MotionDetectorV2 *motion_detector_v2, uint32_t pointer);

/**
 * \ingroup BrickletMotionDetectorV2
 *
 * Writes 64 Bytes of firmware at the position as written by
 * {@link motion_detector_v2_set_write_firmware_pointer} before. The firmware is written
 * to flash every 4 chunks.
 * 
 * You can only write firmware in bootloader mode.
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
int motion_detector_v2_write_firmware(MotionDetectorV2 *motion_detector_v2, uint8_t data[64], uint8_t *ret_status);

/**
 * \ingroup BrickletMotionDetectorV2
 *
 * Sets the status LED configuration. By default the LED shows
 * communication traffic between Brick and Bricklet, it flickers once
 * for every 10 received data packets.
 * 
 * You can also turn the LED permanently on/off or show a heartbeat.
 * 
 * If the Bricklet is in bootloader mode, the LED is will show heartbeat by default.
 */
int motion_detector_v2_set_status_led_config(MotionDetectorV2 *motion_detector_v2, uint8_t config);

/**
 * \ingroup BrickletMotionDetectorV2
 *
 * Returns the configuration as set by {@link motion_detector_v2_set_status_led_config}
 */
int motion_detector_v2_get_status_led_config(MotionDetectorV2 *motion_detector_v2, uint8_t *ret_config);

/**
 * \ingroup BrickletMotionDetectorV2
 *
 * Returns the temperature in °C as measured inside the microcontroller. The
 * value returned is not the ambient temperature!
 * 
 * The temperature is only proportional to the real temperature and it has bad
 * accuracy. Practically it is only useful as an indicator for
 * temperature changes.
 */
int motion_detector_v2_get_chip_temperature(MotionDetectorV2 *motion_detector_v2, int16_t *ret_temperature);

/**
 * \ingroup BrickletMotionDetectorV2
 *
 * Calling this function will reset the Bricklet. All configurations
 * will be lost.
 * 
 * After a reset you have to create new device objects,
 * calling functions on the existing ones will result in
 * undefined behavior!
 */
int motion_detector_v2_reset(MotionDetectorV2 *motion_detector_v2);

/**
 * \ingroup BrickletMotionDetectorV2
 *
 * Writes a new UID into flash. If you want to set a new UID
 * you have to decode the Base58 encoded UID string into an
 * integer first.
 * 
 * We recommend that you use Brick Viewer to change the UID.
 */
int motion_detector_v2_write_uid(MotionDetectorV2 *motion_detector_v2, uint32_t uid);

/**
 * \ingroup BrickletMotionDetectorV2
 *
 * Returns the current UID as an integer. Encode as
 * Base58 to get the usual string version.
 */
int motion_detector_v2_read_uid(MotionDetectorV2 *motion_detector_v2, uint32_t *ret_uid);

/**
 * \ingroup BrickletMotionDetectorV2
 *
 * Returns the UID, the UID where the Bricklet is connected to,
 * the position, the hardware and firmware version as well as the
 * device identifier.
 * 
 * The position can be 'a', 'b', 'c' or 'd'.
 * 
 * The device identifier numbers can be found :ref:`here <device_identifier>`.
 * |device_identifier_constant|
 */
int motion_detector_v2_get_identity(MotionDetectorV2 *motion_detector_v2, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier);

#ifdef __cplusplus
}
#endif

#endif
