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

#include "bricklet_dual_relay.h"

#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif



typedef void (*MonoflopDone_CallbackFunction)(uint8_t relay, bool state, void *user_data);

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
	uint8_t relay1;
	uint8_t relay2;
} ATTRIBUTE_PACKED SetState_Request;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetState_Request;

typedef struct {
	PacketHeader header;
	uint8_t relay1;
	uint8_t relay2;
} ATTRIBUTE_PACKED GetState_Response;

typedef struct {
	PacketHeader header;
	uint8_t relay;
	uint8_t state;
	uint32_t time;
} ATTRIBUTE_PACKED SetMonoflop_Request;

typedef struct {
	PacketHeader header;
	uint8_t relay;
} ATTRIBUTE_PACKED GetMonoflop_Request;

typedef struct {
	PacketHeader header;
	uint8_t state;
	uint32_t time;
	uint32_t time_remaining;
} ATTRIBUTE_PACKED GetMonoflop_Response;

typedef struct {
	PacketHeader header;
	uint8_t relay;
	uint8_t state;
} ATTRIBUTE_PACKED MonoflopDone_Callback;

typedef struct {
	PacketHeader header;
	uint8_t relay;
	uint8_t state;
} ATTRIBUTE_PACKED SetSelectedState_Request;

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

static void dual_relay_callback_wrapper_monoflop_done(DevicePrivate *device_p, Packet *packet) {
	MonoflopDone_CallbackFunction callback_function;
	void *user_data = device_p->registered_callback_user_data[DEVICE_NUM_FUNCTION_IDS + DUAL_RELAY_CALLBACK_MONOFLOP_DONE];
	bool unpacked_state;
	MonoflopDone_Callback *callback = (MonoflopDone_Callback *)packet;

	*(void **)(&callback_function) = device_p->registered_callbacks[DEVICE_NUM_FUNCTION_IDS + DUAL_RELAY_CALLBACK_MONOFLOP_DONE];

	if (callback_function == NULL) {
		return;
	}
	unpacked_state = callback->state != 0;

	callback_function(callback->relay, unpacked_state, user_data);
}

void dual_relay_create(DualRelay *dual_relay, const char *uid, IPConnection *ipcon) {
	DevicePrivate *device_p;

	device_create(dual_relay, uid, ipcon->p, 2, 0, 0);

	device_p = dual_relay->p;

	device_p->response_expected[DUAL_RELAY_FUNCTION_SET_STATE] = DEVICE_RESPONSE_EXPECTED_FALSE;
	device_p->response_expected[DUAL_RELAY_FUNCTION_GET_STATE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	device_p->response_expected[DUAL_RELAY_FUNCTION_SET_MONOFLOP] = DEVICE_RESPONSE_EXPECTED_FALSE;
	device_p->response_expected[DUAL_RELAY_FUNCTION_GET_MONOFLOP] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	device_p->response_expected[DUAL_RELAY_FUNCTION_SET_SELECTED_STATE] = DEVICE_RESPONSE_EXPECTED_FALSE;
	device_p->response_expected[DUAL_RELAY_FUNCTION_GET_IDENTITY] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;

	device_p->callback_wrappers[DUAL_RELAY_CALLBACK_MONOFLOP_DONE] = dual_relay_callback_wrapper_monoflop_done;

}

void dual_relay_destroy(DualRelay *dual_relay) {
	device_release(dual_relay->p);
}

int dual_relay_get_response_expected(DualRelay *dual_relay, uint8_t function_id, bool *ret_response_expected) {
	return device_get_response_expected(dual_relay->p, function_id, ret_response_expected);
}

int dual_relay_set_response_expected(DualRelay *dual_relay, uint8_t function_id, bool response_expected) {
	return device_set_response_expected(dual_relay->p, function_id, response_expected);
}

int dual_relay_set_response_expected_all(DualRelay *dual_relay, bool response_expected) {
	return device_set_response_expected_all(dual_relay->p, response_expected);
}

void dual_relay_register_callback(DualRelay *dual_relay, int16_t callback_id, void *function, void *user_data) {
	device_register_callback(dual_relay->p, callback_id, function, user_data);
}

int dual_relay_get_api_version(DualRelay *dual_relay, uint8_t ret_api_version[3]) {
	return device_get_api_version(dual_relay->p, ret_api_version);
}

int dual_relay_set_state(DualRelay *dual_relay, bool relay1, bool relay2) {
	DevicePrivate *device_p = dual_relay->p;
	SetState_Request request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), DUAL_RELAY_FUNCTION_SET_STATE, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	request.relay1 = relay1 ? 1 : 0;
	request.relay2 = relay2 ? 1 : 0;

	ret = device_send_request(device_p, (Packet *)&request, NULL);

	return ret;
}

int dual_relay_get_state(DualRelay *dual_relay, bool *ret_relay1, bool *ret_relay2) {
	DevicePrivate *device_p = dual_relay->p;
	GetState_Request request;
	GetState_Response response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), DUAL_RELAY_FUNCTION_GET_STATE, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	ret = device_send_request(device_p, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}

	*ret_relay1 = response.relay1 != 0;
	*ret_relay2 = response.relay2 != 0;

	return ret;
}

int dual_relay_set_monoflop(DualRelay *dual_relay, uint8_t relay, bool state, uint32_t time) {
	DevicePrivate *device_p = dual_relay->p;
	SetMonoflop_Request request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), DUAL_RELAY_FUNCTION_SET_MONOFLOP, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	request.relay = relay;
	request.state = state ? 1 : 0;
	request.time = leconvert_uint32_to(time);

	ret = device_send_request(device_p, (Packet *)&request, NULL);

	return ret;
}

int dual_relay_get_monoflop(DualRelay *dual_relay, uint8_t relay, bool *ret_state, uint32_t *ret_time, uint32_t *ret_time_remaining) {
	DevicePrivate *device_p = dual_relay->p;
	GetMonoflop_Request request;
	GetMonoflop_Response response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), DUAL_RELAY_FUNCTION_GET_MONOFLOP, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	request.relay = relay;

	ret = device_send_request(device_p, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}

	*ret_state = response.state != 0;
	*ret_time = leconvert_uint32_from(response.time);
	*ret_time_remaining = leconvert_uint32_from(response.time_remaining);

	return ret;
}

int dual_relay_set_selected_state(DualRelay *dual_relay, uint8_t relay, bool state) {
	DevicePrivate *device_p = dual_relay->p;
	SetSelectedState_Request request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), DUAL_RELAY_FUNCTION_SET_SELECTED_STATE, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	request.relay = relay;
	request.state = state ? 1 : 0;

	ret = device_send_request(device_p, (Packet *)&request, NULL);

	return ret;
}

int dual_relay_get_identity(DualRelay *dual_relay, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier) {
	DevicePrivate *device_p = dual_relay->p;
	GetIdentity_Request request;
	GetIdentity_Response response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), DUAL_RELAY_FUNCTION_GET_IDENTITY, device_p->ipcon_p, device_p);

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
