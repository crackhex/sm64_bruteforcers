#include "bruteforce/common_states/bf_state_definitions_camera.inc.c"
#include "bruteforce/common_states/bf_state_definitions_common.inc.c"

#ifdef BF_STATE_INCLUDE

#include "types.h"
extern struct MarioState *gMarioState;
extern struct Controller testController;
extern f32 minSpeed;

#else

BF_STATIC_STATE(u32, scoring_frame, bfStaticState.scoring_frame)

BF_STATIC_STATE(f32, plane_nx, bfStaticState.plane_nx)
BF_STATIC_STATE(f32, plane_nz, bfStaticState.plane_nz)
BF_STATIC_STATE(f32, plane_d, bfStaticState.plane_d)
BF_STATIC_STATE(s16, approach_angle, bfStaticState.approach_angle)
BF_STATIC_STATE(f32, minimum_h_speed, minSpeed)

BF_STATIC_STATE(Triangles, static_tris, bfStaticState.static_tris)

BF_DYNAMIC_STATE(u16, initial_button_state, testController.buttonDown)

// Mario
BF_DYNAMIC_VEC3(mario, gMarioState->pos)
BF_DYNAMIC_VEC3(mario_vel, gMarioState->vel)
BF_DYNAMIC_STATE(f32, mario_h_speed, gMarioState->forwardVel)
BF_DYNAMIC_STATE(u32, mario_action, gMarioState->action)
BF_DYNAMIC_STATE(u16, mario_action_timer, gMarioState->actionTimer)
BF_DYNAMIC_STATE(u8, mario_wallkick_timer, gMarioState->wallKickTimer)
BF_DYNAMIC_STATE(u32, mario_previous_action, gMarioState->prevAction)
BF_DYNAMIC_STATE(s16, mario_yaw_facing, gMarioState->faceAngle[1])

#endif