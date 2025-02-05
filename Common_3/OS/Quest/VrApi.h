#pragma once

#if defined(QUEST_VR)

#include "../../ThirdParty/OpenSource/ovr_sdk_mobile_1.46.0/VrApi/Include/VrApi.h"
#include "../../ThirdParty/OpenSource/ovr_sdk_mobile_1.46.0/VrApi/Include/VrApi_Helpers.h"
#include "../Interfaces/IOperatingSystem.h"
#include "../Math/MathTypes.h"

struct QuestVR
{
	ovrMobile* pOvr;
	ovrJava mJava;
	double mPredictedDisplayTime;
	unsigned long long mFrameIndex;
	ovrTracking2 mHeadsetTracking;
	uint mEyeTextureWidth;
	uint mEyeTextureHeight;
	mat4 mViewMatrix;
	bool mFoveatedRenderingEnabled;
	bool isSrgb;
};

bool initVrApi(android_app* pAndroidApp, JNIEnv* pJavaEnv);
void exitVrApi();
void updateVrApi();

void hook_poll_events(bool appResumed, bool windowReady, ANativeWindow* nativeWindow);

#endif
