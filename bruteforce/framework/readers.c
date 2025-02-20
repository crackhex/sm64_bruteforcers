#include "sm64.h"
#include <stdlib.h>
#include <string.h>
#include "bruteforce/framework/json.h"
#include "bruteforce/framework/readers.h"

#define read_int(cast_type) \
void read_##cast_type(Json *jsonNode, cast_type *target) { \
	if (jsonNode->type == Json_String) { \
		char* end; \
		*target = (cast_type)strtol(jsonNode->valueString, &end, 0); \
	} \
	else *target = (cast_type)jsonNode->valueInt; \
}

read_int(s32)
read_int(s16)
read_int(u32)
read_int(u16)
read_int(u8)
#undef read_int

void read_f32(Json *jsonNode, f32 *target) {
	*target = (f32)jsonNode->valueFloat;
}

void read_f64(Json *jsonNode, f64 *target) {
	*target = (f64)jsonNode->valueFloat;
}

void read_string(Json *jsonNode, string *target) {
	*target = strdup(jsonNode->valueString);
}

void read_boolean(Json *jsonNode, boolean *target) {
	if (jsonNode->type == Json_String) {
		char *p = jsonNode->valueString;
		for ( ; *p; ++p) *p = tolower(*p);
		if (strcmp(jsonNode->valueString, "true") == 0)
			*target = 1;
		else if (strcmp(jsonNode->valueString, "false") == 0)
			*target = 0;
	}
	else if (jsonNode->type == Json_Number)
		*target = (jsonNode->valueInt != 0) ? 1 : 0;
}

f32 advance_read(Json **nodePtr) {
	f32 val = (*nodePtr)->valueFloat;
	*nodePtr = (*nodePtr)->next;
	return val;
}

void read_Vec3f(Json *jsonNode, Vec3f *target) {
	(*target)[0] = advance_read(&jsonNode);
	(*target)[1] = advance_read(&jsonNode);
	(*target)[2] = advance_read(&jsonNode);
}

void read_Triangles(Json *jsonNode, Triangles *target) {
	Json *triNode = jsonNode->child;
	target->data_size = jsonNode->size;
	target->data = calloc(target->data_size, sizeof(Triangle));
	u32 i = 0;
	while (triNode != NULL) {
		Json *vertNode = triNode->child;
		#define ADVANCE \
			(s16)vertNode->valueInt; \
			vertNode = vertNode->next;
		
		target->data[i].x1 = ADVANCE
		target->data[i].y1 = ADVANCE
		target->data[i].z1 = ADVANCE
		target->data[i].x2 = ADVANCE
		target->data[i].y2 = ADVANCE
		target->data[i].z2 = ADVANCE
		target->data[i].x3 = ADVANCE
		target->data[i].y3 = ADVANCE
		target->data[i].z3 = ADVANCE
		if (vertNode) {
			target->data[i].surf_type = ADVANCE
		}
		i++;
		triNode = triNode->next;

		#undef ADVANCE
	}
}

void read_EnvironmentRegions(Json *jsonNode, EnvironmentRegions *target) {
	*target = calloc(jsonNode->size, sizeof(s16));
	u32 i;
	Json *n = jsonNode->child;
	for (i = 0; i < jsonNode->size; i++) {
		(*target)[i] = n->valueInt;
		n = n->next;
	}
}

void read_Coins(Json *jsonNode, Coins *target) {
	Json *triNode = jsonNode->child;
	target->data_size = jsonNode->size;
	target->data = calloc(target->data_size, sizeof(Triangle));
	u32 i = 0;
	while (triNode != NULL) {
		Json *vertNode = triNode->child;
		#define ADVANCE \
			(s16)vertNode->valueInt; \
			vertNode = vertNode->next;
		
		target->data[i].x = ADVANCE
		target->data[i].y = ADVANCE
		target->data[i].z = ADVANCE

		i++;
		triNode = triNode->next;

		#undef ADVANCE
	}
}