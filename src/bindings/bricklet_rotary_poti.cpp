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

#include "bricklet_rotary_poti.h"

#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif



typedef void (*Position_CallbackFunction)(int16_t position, void *user_data);

typedef void (*AnalogValue_CallbackFunction)(uint16_t value, void *user_data);

typedef void (*PositionReached_CallbackFunction)(int16_t position, void *user_data);

typedef void (*AnalogValueReached_CallbackFunction)(uint16_t value, void *user_data);

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
} ATTRIBUTE_PACKED GetPosition_Request;

typedef struct {
	PacketHeader header;
	int16_t position;
} ATTRIBUTE_PACKED GetPosition_Response;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetAnalogValue_Request;

typedef struct {
	PacketHeader header;
	uint16_t value;
} ATTRIBUTE_PACKED GetAnalogValue_Response;

typedef struct {
	PacketHeader header;
	uint32_t period;
} ATTRIBUTE_PACKED SetPositionCallbackPeriod_Request;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetPositionCallbackPeriod_Request;

typedef struct {
	PacketHeader header;
	uint32_t period;
} ATTRIBUTE_PACKED GetPositionCallbackPeriod_Response;

typedef struct {
	PacketHeader header;
	uint32_t period;
} ATTRIBUTE_PACKED SetAnalogValueCallbackPeriod_Request;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetAnalogValueCallbackPeriod_Request;

typedef struct {
	PacketHeader header;
	uint32_t period;
} ATTRIBUTE_PACKED GetAnalogValueCallbackPeriod_Response;

typedef struct {
	PacketHeader header;
	char option;
	int16_t min;
	int16_t max;
} ATTRIBUTE_PACKED SetPositionCallbackThreshold_Request;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetPositionCallbackThreshold_Request;

typedef struct {
	PacketHeader header;
	char option;
	int16_t min;
	int16_t max;
} ATTRIBUTE_PACKED GetPositionCallbackThreshold_Response;

typedef struct {
	PacketHeader header;
	char option;
	uint16_t min;
	uint16_t max;
} ATTRIBUTE_PACKED SetAnalogValueCallbackThreshold_Request;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetAnalogValueCallbackThreshold_Request;

typedef struct {
	PacketHeader header;
	char option;
	uint16_t min;
	uint16_t max;
} ATTRIBUTE_PACKED GetAnalogValueCallbackThreshold_Response;

typedef struct {
	PacketHeader header;
	uint32_t debounce;
} ATTRIBUTE_PACKED SetDebouncePeriod_Request;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetDebouncePeriod_Request;

typedef struct {
	PacketHeader header;
	uint32_t debounce;
} ATTRIBUTE_PACKED GetDebouncePeriod_Response;

typedef struct {
	PacketHeader header;
	int16_t position;
} ATTRIBUTE_PACKED Position_Callback;

typedef struct {
	PacketHeader header;
	uint16_t value;
} ATTRIBUTE_PACKED AnalogValue_Callback;

typedef struct {
	PacketHeader header;
	int16_t position;
} ATTRIBUTE_PACKED PositionReached_Callback;

typedef struct {
	PacketHeader header;
	uint16_t value;
} ATTRIBUTE_PACKED AnalogValueReached_Callback;

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

static void rotary_poti_callback_wrapper_position(DevicePrivate *device_p, Packet *packet) {
	Position_CallbackFunction callback_function;
	void *user_data = device_p->registered_callback_user_data[DEVICE_NUM_FUNCTION_IDS + ROTARY_POTI_CALLBACK_POSITION];
	Position_Callback *callback = (Position_Callback *)packet;

	*(void **)(&callback_function) = device_p->registered_callbacks[DEVICE_NUM_FUNCTION_IDS + ROTARY_POTI_CALLBACK_POSITION];

	if (callback_function == NULL) {
		return;
	}

	callback->position = leconvert_int16_from(callback->position);

	callback_function(callback->position, user_data);
}

static void rotary_poti_callback_wrapper_analog_value(DevicePrivate *device_p, Packet *packet) {
	AnalogValue_CallbackFunction callback_function;
	void *user_data = device_p->registered_callback_user_data[DEVICE_NUM_FUNCTION_IDS + ROTARY_POTI_CALLBACK_ANALOG_VALUE];
	AnalogValue_Callback *callback = (AnalogValue_Callback *)packet;

	*(void **)(&callback_function) = device_p->registered_callbacks[DEVICE_NUM_FUNCTION_IDS + ROTARY_POTI_CALLBACK_ANALOG_VALUE];

	if (callback_function == NULL) {
		return;
	}

	callback->value = leconvert_uint16_from(callback->value);

	callback_function(callback->value, user_data);
}

static void rotary_poti_callback_wrapper_position_reached(DevicePrivate *device_p, Packet *packet) {
	PositionReached_CallbackFunction callback_function;
	void *user_data = device_p->registered_callback_user_data[DEVICE_NUM_FUNCTION_IDS + ROTARY_POTI_CALLBACK_POSITION_REACHED];
	PositionReached_Callback *callback = (PositionReached_Callback *)packet;

	*(void **)(&callback_function) = device_p->registered_callbacks[DEVICE_NUM_FUNCTION_IDS + ROTARY_POTI_CALLBACK_POSITION_REACHED];

	if (callback_function == NULL) {
		return;
	}

	callback->position = leconvert_int16_from(callback->position);

	callback_function(callback->position, user_data);
}

static void rotary_poti_callback_wrapper_analog_value_reached(DevicePrivate *device_p, Packet *packet) {
	AnalogValueReached_CallbackFunction callback_function;
	void *user_data = device_p->registered_callback_user_data[DEVICE_NUM_FUNCTION_IDS + ROTARY_POTI_CALLBACK_ANALOG_VALUE_REACHED];
	AnalogValueReached_Callback *callback = (AnalogValueReached_Callback *)packet;

	*(void **)(&callback_function) = device_p->registered_callbacks[DEVICE_NUM_FUNCTION_IDS + ROTARY_POTI_CALLBACK_ANALOG_VALUE_REACHED];

	if (callback_function == NULL) {
		return;
	}

	callback->value = leconvert_uint16_from(callback->value);

	callback_function(callback->value, user_data);
}

void rotary_poti_create(RotaryPoti *rotary_poti, const char *uid, IPConnection *ipcon) {
	DevicePrivate *device_p;

	device_create(rotary_poti, uid, ipcon->p, 2, 0, 0);

	device_p = rotary_poti->p;

	device_p->response_expected[ROTARY_POTI_FUNCTION_GET_POSITION] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	device_p->response_expected[ROTARY_POTI_FUNCTION_GET_ANALOG_VALUE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	device_p->response_expected[ROTARY_POTI_FUNCTION_SET_POSITION_CALLBACK_PERIOD] = DEVICE_RESPONSE_EXPECTED_TRUE;
	device_p->response_expected[ROTARY_POTI_FUNCTION_GET_POSITION_CALLBACK_PERIOD] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	device_p->response_expected[ROTARY_POTI_FUNCTION_SET_ANALOG_VALUE_CALLBACK_PERIOD] = DEVICE_RESPONSE_EXPECTED_TRUE;
	device_p->response_expected[ROTARY_POTI_FUNCTION_GET_ANALOG_VALUE_CALLBACK_PERIOD] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	device_p->response_expected[ROTARY_POTI_FUNCTION_SET_POSITION_CALLBACK_THRESHOLD] = DEVICE_RESPONSE_EXPECTED_TRUE;
	device_p->response_expected[ROTARY_POTI_FUNCTION_GET_POSITION_CALLBACK_THRESHOLD] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	device_p->response_expected[ROTARY_POTI_FUNCTION_SET_ANALOG_VALUE_CALLBACK_THRESHOLD] = DEVICE_RESPONSE_EXPECTED_TRUE;
	device_p->response_expected[ROTARY_POTI_FUNCTION_GET_ANALOG_VALUE_CALLBACK_THRESHOLD] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	device_p->response_expected[ROTARY_POTI_FUNCTION_SET_DEBOUNCE_PERIOD] = DEVICE_RESPONSE_EXPECTED_TRUE;
	device_p->response_expected[ROTARY_POTI_FUNCTION_GET_DEBOUNCE_PERIOD] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	device_p->response_expected[ROTARY_POTI_FUNCTION_GET_IDENTITY] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;

	device_p->callback_wrappers[ROTARY_POTI_CALLBACK_POSITION] = rotary_poti_callback_wrapper_position;
	device_p->callback_wrappers[ROTARY_POTI_CALLBACK_ANALOG_VALUE] = rotary_poti_callback_wrapper_analog_value;
	device_p->callback_wrappers[ROTARY_POTI_CALLBACK_POSITION_REACHED] = rotary_poti_callback_wrapper_position_reached;
	device_p->callback_wrappers[ROTARY_POTI_CALLBACK_ANALOG_VALUE_REACHED] = rotary_poti_callback_wrapper_analog_value_reached;

}

void rotary_poti_destroy(RotaryPoti *rotary_poti) {
	device_release(rotary_poti->p);
}

int rotary_poti_get_response_expected(RotaryPoti *rotary_poti, uint8_t function_id, bool *ret_response_expected) {
	return device_get_response_expected(rotary_poti->p, function_id, ret_response_expected);
}

int rotary_poti_set_response_expected(RotaryPoti *rotary_poti, uint8_t function_id, bool response_expected) {
	return device_set_response_expected(rotary_poti->p, function_id, response_expected);
}

int rotary_poti_set_response_expected_all(RotaryPoti *rotary_poti, bool response_expected) {
	return device_set_response_expected_all(rotary_poti->p, response_expected);
}

void rotary_poti_register_callback(RotaryPoti *rotary_poti, int16_t callback_id, void *function, void *user_data) {
	device_register_callback(rotary_poti->p, callback_id, function, user_data);
}

int rotary_poti_get_api_version(RotaryPoti *rotary_poti, uint8_t ret_api_version[3]) {
	return device_get_api_version(rotary_poti->p, ret_api_version);
}

int rotary_poti_get_position(RotaryPoti *rotary_poti, int16_t *ret_position) {
	DevicePrivate *device_p = rotary_poti->p;
	GetPosition_Request request;
	GetPosition_Response response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), ROTARY_POTI_FUNCTION_GET_POSITION, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	ret = device_send_request(device_p, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}

	*ret_position = leconvert_int16_from(response.position);

	return ret;
}

int rotary_poti_get_analog_value(RotaryPoti *rotary_poti, uint16_t *ret_value) {
	DevicePrivate *device_p = rotary_poti->p;
	GetAnalogValue_Request request;
	GetAnalogValue_Response response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), ROTARY_POTI_FUNCTION_GET_ANALOG_VALUE, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	ret = device_send_request(device_p, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}

	*ret_value = leconvert_uint16_from(response.value);

	return ret;
}

int rotary_poti_set_position_callback_period(RotaryPoti *rotary_poti, uint32_t period) {
	DevicePrivate *device_p = rotary_poti->p;
	SetPositionCallbackPeriod_Request request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), ROTARY_POTI_FUNCTION_SET_POSITION_CALLBACK_PERIOD, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	request.period = leconvert_uint32_to(period);

	ret = device_send_request(device_p, (Packet *)&request, NULL);

	return ret;
}

int rotary_poti_get_position_callback_period(RotaryPoti *rotary_poti, uint32_t *ret_period) {
	DevicePrivate *device_p = rotary_poti->p;
	GetPositionCallbackPeriod_Request request;
	GetPositionCallbackPeriod_Response response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), ROTARY_POTI_FUNCTION_GET_POSITION_CALLBACK_PERIOD, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	ret = device_send_request(device_p, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}

	*ret_period = leconvert_uint32_from(response.period);

	return ret;
}

int rotary_poti_set_analog_value_callback_period(RotaryPoti *rotary_poti, uint32_t period) {
	DevicePrivate *device_p = rotary_poti->p;
	SetAnalogValueCallbackPeriod_Request request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), ROTARY_POTI_FUNCTION_SET_ANALOG_VALUE_CALLBACK_PERIOD, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	request.period = leconvert_uint32_to(period);

	ret = device_send_request(device_p, (Packet *)&request, NULL);

	return ret;
}

int rotary_poti_get_analog_value_callback_period(RotaryPoti *rotary_poti, uint32_t *ret_period) {
	DevicePrivate *device_p = rotary_poti->p;
	GetAnalogValueCallbackPeriod_Request request;
	GetAnalogValueCallbackPeriod_Response response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), ROTARY_POTI_FUNCTION_GET_ANALOG_VALUE_CALLBACK_PERIOD, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	ret = device_send_request(device_p, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}

	*ret_period = leconvert_uint32_from(response.period);

	return ret;
}

int rotary_poti_set_position_callback_threshold(RotaryPoti *rotary_poti, char option, int16_t min, int16_t max) {
	DevicePrivate *device_p = rotary_poti->p;
	SetPositionCallbackThreshold_Request request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), ROTARY_POTI_FUNCTION_SET_POSITION_CALLBACK_THRESHOLD, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	request.option = option;
	request.min = leconvert_int16_to(min);
	request.max = leconvert_int16_to(max);

	ret = device_send_request(device_p, (Packet *)&request, NULL);

	return ret;
}

int rotary_poti_get_position_callback_threshold(RotaryPoti *rotary_poti, char *ret_option, int16_t *ret_min, int16_t *ret_max) {
	DevicePrivate *device_p = rotary_poti->p;
	GetPositionCallbackThreshold_Request request;
	GetPositionCallbackThreshold_Response response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), ROTARY_POTI_FUNCTION_GET_POSITION_CALLBACK_THRESHOLD, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	ret = device_send_request(device_p, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}

	*ret_option = response.option;
	*ret_min = leconvert_int16_from(response.min);
	*ret_max = leconvert_int16_from(response.max);

	return ret;
}

int rotary_poti_set_analog_value_callback_threshold(RotaryPoti *rotary_poti, char option, uint16_t min, uint16_t max) {
	DevicePrivate *device_p = rotary_poti->p;
	SetAnalogValueCallbackThreshold_Request request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), ROTARY_POTI_FUNCTION_SET_ANALOG_VALUE_CALLBACK_THRESHOLD, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	request.option = option;
	request.min = leconvert_uint16_to(min);
	request.max = leconvert_uint16_to(max);

	ret = device_send_request(device_p, (Packet *)&request, NULL);

	return ret;
}

int rotary_poti_get_analog_value_callback_threshold(RotaryPoti *rotary_poti, char *ret_option, uint16_t *ret_min, uint16_t *ret_max) {
	DevicePrivate *device_p = rotary_poti->p;
	GetAnalogValueCallbackThreshold_Request request;
	GetAnalogValueCallbackThreshold_Response response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), ROTARY_POTI_FUNCTION_GET_ANALOG_VALUE_CALLBACK_THRESHOLD, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	ret = device_send_request(device_p, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}

	*ret_option = response.option;
	*ret_min = leconvert_uint16_from(response.min);
	*ret_max = leconvert_uint16_from(response.max);

	return ret;
}

int rotary_poti_set_debounce_period(RotaryPoti *rotary_poti, uint32_t debounce) {
	DevicePrivate *device_p = rotary_poti->p;
	SetDebouncePeriod_Request request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), ROTARY_POTI_FUNCTION_SET_DEBOUNCE_PERIOD, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	request.debounce = leconvert_uint32_to(debounce);

	ret = device_send_request(device_p, (Packet *)&request, NULL);

	return ret;
}

int rotary_poti_get_debounce_period(RotaryPoti *rotary_poti, uint32_t *ret_debounce) {
	DevicePrivate *device_p = rotary_poti->p;
	GetDebouncePeriod_Request request;
	GetDebouncePeriod_Response response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), ROTARY_POTI_FUNCTION_GET_DEBOUNCE_PERIOD, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	ret = device_send_request(device_p, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}

	*ret_debounce = leconvert_uint32_from(response.debounce);

	return ret;
}

int rotary_poti_get_identity(RotaryPoti *rotary_poti, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier) {
	DevicePrivate *device_p = rotary_poti->p;
	GetIdentity_Request request;
	GetIdentity_Response response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), ROTARY_POTI_FUNCTION_GET_IDENTITY, device_p->ipcon_p, device_p);

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
