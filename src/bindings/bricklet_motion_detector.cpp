/* ***********************************************************
 * This file was automatically generated on 2018-06-08.      *
 *                                                           *
 * C/C++ Bindings Version 2.1.20                             *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/


#define IPCON_EXPOSE_INTERNALS

#include "bricklet_motion_detector.h"

#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif



typedef void (*MotionDetected_CallbackFunction)(void *user_data);

typedef void (*DetectionCycleEnded_CallbackFunction)(void *user_data);

#if defined _MSC_VER || defined __BORLANDC__
	#pragma pack(push)
	#pragma pack(1)
	#define ATTRIBUTE_PACKED
#elif defined __GNUC__
	#ifdef _WIN32
		// workaround struct packing bug in GCC 4.7 on Windows
		// http://gcc.gnu.org/bugzilla/show_bug.cgi?id=52991
		#define ATTRIBUTE_PACKED __attribute__((gcc_struct, packed))
	#else
		#define ATTRIBUTE_PACKED __attribute__((packed))
	#endif
#else
	#error unknown compiler, do not know how to enable struct packing
#endif

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetMotionDetected_Request;

typedef struct {
	PacketHeader header;
	uint8_t motion;
} ATTRIBUTE_PACKED GetMotionDetected_Response;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED MotionDetected_Callback;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED DetectionCycleEnded_Callback;

typedef struct {
	PacketHeader header;
	uint8_t config;
} ATTRIBUTE_PACKED SetStatusLEDConfig_Request;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetStatusLEDConfig_Request;

typedef struct {
	PacketHeader header;
	uint8_t config;
} ATTRIBUTE_PACKED GetStatusLEDConfig_Response;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetIdentity_Request;

typedef struct {
	PacketHeader header;
	char uid[8];
	char connected_uid[8];
	char position;
	uint8_t hardware_version[3];
	uint8_t firmware_version[3];
	uint16_t device_identifier;
} ATTRIBUTE_PACKED GetIdentity_Response;

#if defined _MSC_VER || defined __BORLANDC__
	#pragma pack(pop)
#endif
#undef ATTRIBUTE_PACKED

static void motion_detector_callback_wrapper_motion_detected(DevicePrivate *device_p, Packet *packet) {
	MotionDetected_CallbackFunction callback_function;
	void *user_data = device_p->registered_callback_user_data[DEVICE_NUM_FUNCTION_IDS + MOTION_DETECTOR_CALLBACK_MOTION_DETECTED];
	(void)packet;

	*(void **)(&callback_function) = device_p->registered_callbacks[DEVICE_NUM_FUNCTION_IDS + MOTION_DETECTOR_CALLBACK_MOTION_DETECTED];

	if (callback_function == NULL) {
		return;
	}

	callback_function(user_data);
}

static void motion_detector_callback_wrapper_detection_cycle_ended(DevicePrivate *device_p, Packet *packet) {
	DetectionCycleEnded_CallbackFunction callback_function;
	void *user_data = device_p->registered_callback_user_data[DEVICE_NUM_FUNCTION_IDS + MOTION_DETECTOR_CALLBACK_DETECTION_CYCLE_ENDED];
	(void)packet;

	*(void **)(&callback_function) = device_p->registered_callbacks[DEVICE_NUM_FUNCTION_IDS + MOTION_DETECTOR_CALLBACK_DETECTION_CYCLE_ENDED];

	if (callback_function == NULL) {
		return;
	}

	callback_function(user_data);
}

void motion_detector_create(MotionDetector *motion_detector, const char *uid, IPConnection *ipcon) {
	DevicePrivate *device_p;

	device_create(motion_detector, uid, ipcon->p, 2, 0, 1);

	device_p = motion_detector->p;

	device_p->response_expected[MOTION_DETECTOR_FUNCTION_GET_MOTION_DETECTED] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	device_p->response_expected[MOTION_DETECTOR_FUNCTION_SET_STATUS_LED_CONFIG] = DEVICE_RESPONSE_EXPECTED_FALSE;
	device_p->response_expected[MOTION_DETECTOR_FUNCTION_GET_STATUS_LED_CONFIG] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	device_p->response_expected[MOTION_DETECTOR_FUNCTION_GET_IDENTITY] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;

	device_p->callback_wrappers[MOTION_DETECTOR_CALLBACK_MOTION_DETECTED] = motion_detector_callback_wrapper_motion_detected;
	device_p->callback_wrappers[MOTION_DETECTOR_CALLBACK_DETECTION_CYCLE_ENDED] = motion_detector_callback_wrapper_detection_cycle_ended;

}

void motion_detector_destroy(MotionDetector *motion_detector) {
	device_release(motion_detector->p);
}

int motion_detector_get_response_expected(MotionDetector *motion_detector, uint8_t function_id, bool *ret_response_expected) {
	return device_get_response_expected(motion_detector->p, function_id, ret_response_expected);
}

int motion_detector_set_response_expected(MotionDetector *motion_detector, uint8_t function_id, bool response_expected) {
	return device_set_response_expected(motion_detector->p, function_id, response_expected);
}

int motion_detector_set_response_expected_all(MotionDetector *motion_detector, bool response_expected) {
	return device_set_response_expected_all(motion_detector->p, response_expected);
}

void motion_detector_register_callback(MotionDetector *motion_detector, int16_t callback_id, void *function, void *user_data) {
	device_register_callback(motion_detector->p, callback_id, function, user_data);
}

int motion_detector_get_api_version(MotionDetector *motion_detector, uint8_t ret_api_version[3]) {
	return device_get_api_version(motion_detector->p, ret_api_version);
}

int motion_detector_get_motion_detected(MotionDetector *motion_detector, uint8_t *ret_motion) {
	DevicePrivate *device_p = motion_detector->p;
	GetMotionDetected_Request request;
	GetMotionDetected_Response response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), MOTION_DETECTOR_FUNCTION_GET_MOTION_DETECTED, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	ret = device_send_request(device_p, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}

	*ret_motion = response.motion;

	return ret;
}

int motion_detector_set_status_led_config(MotionDetector *motion_detector, uint8_t config) {
	DevicePrivate *device_p = motion_detector->p;
	SetStatusLEDConfig_Request request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), MOTION_DETECTOR_FUNCTION_SET_STATUS_LED_CONFIG, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	request.config = config;

	ret = device_send_request(device_p, (Packet *)&request, NULL);

	return ret;
}

int motion_detector_get_status_led_config(MotionDetector *motion_detector, uint8_t *ret_config) {
	DevicePrivate *device_p = motion_detector->p;
	GetStatusLEDConfig_Request request;
	GetStatusLEDConfig_Response response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), MOTION_DETECTOR_FUNCTION_GET_STATUS_LED_CONFIG, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	ret = device_send_request(device_p, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}

	*ret_config = response.config;

	return ret;
}

int motion_detector_get_identity(MotionDetector *motion_detector, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier) {
	DevicePrivate *device_p = motion_detector->p;
	GetIdentity_Request request;
	GetIdentity_Response response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), MOTION_DETECTOR_FUNCTION_GET_IDENTITY, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	ret = device_send_request(device_p, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}

	memcpy(ret_uid, response.uid, 8);
	memcpy(ret_connected_uid, response.connected_uid, 8);
	*ret_position = response.position;
	memcpy(ret_hardware_version, response.hardware_version, 3 * sizeof(uint8_t));
	memcpy(ret_firmware_version, response.firmware_version, 3 * sizeof(uint8_t));
	*ret_device_identifier = leconvert_uint16_from(response.device_identifier);

	return ret;
}

#ifdef __cplusplus
}
#endif
