#include "bruteforce/common_states/bf_state_definitions_camera.inc.c"
#include "bruteforce/common_states/bf_state_definitions_common.inc.c"
#include "bruteforce/algorithms/genetic/bf_state_definitions_genetic.inc.c"

#ifdef BF_STATE_INCLUDE

#include "types.h"
#include "scoring_method.h"
#include "perturbator.h"
extern struct MarioState *gMarioState;
extern f32 minSpeed;
extern s16 sSwimStrength;
extern s16 gCurrLevelNum;
extern s16 gCurrCourseNum;

#else

// scoring parameters
BF_STATIC_STATE(boolean, relative_frame_numbers, bfStaticState.relative_frame_numbers)
BF_STATIC_STATE(boolean, score_on_last_frame, bfStaticState.score_on_last_frame)
BF_STATIC_STATE(ScoringMethods, scoring_methods, bfStaticState.scoring_methods)
BF_STATIC_STATE(Perturbators, perturbators, bfStaticState.perturbators)
__NL__

BF_STATIC_STATE(s16, level_num, gCurrLevelNum)
BF_STATIC_STATE(s16, course_num, gCurrCourseNum)

// World triangles
BF_STATIC_STATE(Triangles, dynamic_tris, bfStaticState.dynamic_tris)
BF_STATIC_STATE(Triangles, static_tris, bfStaticState.static_tris)
__NL__

// Mario
BF_DYNAMIC_STATE(s16, mario_health, gMarioState->health)
BF_DYNAMIC_VEC3(mario, gMarioState->pos)
BF_DYNAMIC_VEC3(mario_vel, gMarioState->vel)
BF_DYNAMIC_STATE(f32, mario_h_speed, gMarioState->forwardVel)
BF_DYNAMIC_STATE(f32, mario_slide_vel_x, gMarioState->slideVelX)
BF_DYNAMIC_STATE(f32, mario_slide_vel_z, gMarioState->slideVelZ)
BF_DYNAMIC_STATE(u32, mario_action, gMarioState->action)
BF_DYNAMIC_STATE(u16, mario_action_timer, gMarioState->actionTimer)
BF_DYNAMIC_STATE(u8, mario_wallkick_timer, gMarioState->wallKickTimer)
BF_DYNAMIC_STATE(u32, mario_previous_action, gMarioState->prevAction)
BF_DYNAMIC_STATE(s16, mario_yaw_facing, gMarioState->faceAngle[1])
BF_DYNAMIC_STATE(s16, mario_slide_yaw, gMarioState->slideYaw)
BF_DYNAMIC_STATE(u16, area_terrain_type, gMarioState->area->terrainType)

#endif