#pragma once

#ifndef _controllerBindings_
#define _controllerBindings_


#define INDEX_AClick           0x0001
#define INDEX_ATouch           0x0002
#define INDEX_BClick           0x0004
#define INDEX_BTouch           0x0008
#define INDEX_SYSClick         0x0010
#define INDEX_ThumbStickClick  0x0020
#define INDEX_FingerIndex      0x0040
#define INDEX_FingerMiddle     0x0080
#define INDEX_FingerRing       0x0100
#define INDEX_FingerPinky      0x0200
#define INDEX_TrackpadTouch    0x0400
#define INDEX_ThumbStickTouch  0x0800

#define HTC_SysClick		0x0001
#define HTC_MenuClick		0x0004
#define HTC_ThumbstickClick 0x0020
#define HTC_GripClick		0x0080
#define HTC_ThumbstickTouch 0x0800

#include <openvr_driver.h>
#include "dataHandler.h"

vr::VRInputComponentHandle_t HButtonsCtrlRight[11], HAnalogCtrlRight[12];
vr::VRInputComponentHandle_t HButtonsCtrlLeft[11], HAnalogCtrlLeft[12];

TController RightCtrl, LeftCtrl;

CdataHandler dH;

void initController(int contType, int contIndex, vr::PropertyContainerHandle_t m_ulPropertyContainer, vr::VRInputComponentHandle_t m_skeletonHandle, vr::VRInputComponentHandle_t &haptic)
{
	switch (contType) 
	{
	case 0:
		if (contIndex == 1) {
	
			vr::VRProperties()->SetInt32Property(m_ulPropertyContainer, vr::Prop_ControllerRoleHint_Int32, vr::TrackedControllerRole_RightHand);
			vr::VRProperties()->SetStringProperty(m_ulPropertyContainer, vr::Prop_ModelNumber_String, "Knuckles Right");
			vr::VRProperties()->SetStringProperty(m_ulPropertyContainer, vr::Prop_RenderModelName_String, "{indexcontroller}valve_controller_knu_1_0_right");
			vr::VRProperties()->SetStringProperty(m_ulPropertyContainer, vr::Prop_Firmware_ProgrammingTarget_String, "LHR-E217CD01");
			vr::VRProperties()->SetStringProperty(m_ulPropertyContainer, vr::Prop_RegisteredDeviceType_String, "valve/index_controllerLHR-E217CD01");
			vr::VRProperties()->SetStringProperty(m_ulPropertyContainer, vr::Prop_NamedIconPathDeviceOff_String, "{indexcontroller}/icons/right_controller_status_off.png");
			vr::VRProperties()->SetStringProperty(m_ulPropertyContainer, vr::Prop_NamedIconPathDeviceSearching_String, "{indexcontroller}/icons/right_controller_status_searching.gif");
			vr::VRProperties()->SetStringProperty(m_ulPropertyContainer, vr::Prop_NamedIconPathDeviceSearchingAlert_String, "{indexcontroller}/icons//right_controller_status_searching_alert.gif");
			vr::VRProperties()->SetStringProperty(m_ulPropertyContainer, vr::Prop_NamedIconPathDeviceReady_String, "{indexcontroller}/icons//right_controller_status_ready.png");
			vr::VRProperties()->SetStringProperty(m_ulPropertyContainer, vr::Prop_NamedIconPathDeviceReadyAlert_String, "{indexcontroller}/icons//right_controller_status_ready_alert.png");
			vr::VRProperties()->SetStringProperty(m_ulPropertyContainer, vr::Prop_NamedIconPathDeviceNotReady_String, "{indexcontroller}/icons//right_controller_status_error.png");
			vr::VRProperties()->SetStringProperty(m_ulPropertyContainer, vr::Prop_NamedIconPathDeviceStandby_String, "{indexcontroller}/icons//right_controller_status_off.png");
			vr::VRProperties()->SetStringProperty(m_ulPropertyContainer, vr::Prop_NamedIconPathDeviceAlertLow_String, "{indexcontroller}/icons//right_controller_status_ready_low.png");
			vr::VRProperties()->SetStringProperty(m_ulPropertyContainer, vr::Prop_SerialNumber_String, "LHR-E217CD01");
			vr::VRDriverInput()->CreateSkeletonComponent(m_ulPropertyContainer, "/input/skeleton/right", "/skeleton/hand/right", "/pose/raw", vr::VRSkeletalTracking_Partial, nullptr, 0U, &m_skeletonHandle);
			

			vr::VRDriverInput()->CreateScalarComponent(m_ulPropertyContainer, "/input/thumbstick/x", &HAnalogCtrlRight[0], vr::VRScalarType_Absolute, vr::VRScalarUnits_NormalizedTwoSided);
			vr::VRDriverInput()->CreateScalarComponent(m_ulPropertyContainer, "/input/thumbstick/y", &HAnalogCtrlRight[1], vr::VRScalarType_Absolute, vr::VRScalarUnits_NormalizedTwoSided);
			vr::VRDriverInput()->CreateScalarComponent(m_ulPropertyContainer, "/input/trigger/value", &HAnalogCtrlRight[2], vr::EVRScalarType::VRScalarType_Absolute, vr::EVRScalarUnits::VRScalarUnits_NormalizedOneSided);
			vr::VRDriverInput()->CreateScalarComponent(m_ulPropertyContainer, "/input/trackpad/x", &HAnalogCtrlRight[3], vr::VRScalarType_Absolute, vr::VRScalarUnits_NormalizedTwoSided);
			vr::VRDriverInput()->CreateScalarComponent(m_ulPropertyContainer, "/input/trackpad/y", &HAnalogCtrlRight[4], vr::VRScalarType_Absolute, vr::VRScalarUnits_NormalizedTwoSided);
			vr::VRDriverInput()->CreateScalarComponent(m_ulPropertyContainer, "/input/trackpad/force", &HAnalogCtrlRight[5], vr::EVRScalarType::VRScalarType_Absolute, vr::EVRScalarUnits::VRScalarUnits_NormalizedOneSided);
			vr::VRDriverInput()->CreateScalarComponent(m_ulPropertyContainer, "/input/finger/index", &HAnalogCtrlRight[6], vr::EVRScalarType::VRScalarType_Absolute, vr::EVRScalarUnits::VRScalarUnits_NormalizedOneSided);
			vr::VRDriverInput()->CreateScalarComponent(m_ulPropertyContainer, "/input/finger/middle", &HAnalogCtrlRight[7], vr::EVRScalarType::VRScalarType_Absolute, vr::EVRScalarUnits::VRScalarUnits_NormalizedOneSided);
			vr::VRDriverInput()->CreateScalarComponent(m_ulPropertyContainer, "/input/finger/ring", &HAnalogCtrlRight[8], vr::EVRScalarType::VRScalarType_Absolute, vr::EVRScalarUnits::VRScalarUnits_NormalizedOneSided);
			vr::VRDriverInput()->CreateScalarComponent(m_ulPropertyContainer, "/input/finger/pinky", &HAnalogCtrlRight[9], vr::EVRScalarType::VRScalarType_Absolute, vr::EVRScalarUnits::VRScalarUnits_NormalizedOneSided);
			vr::VRDriverInput()->CreateScalarComponent(m_ulPropertyContainer, "/input/grip/force", &HAnalogCtrlRight[10], vr::EVRScalarType::VRScalarType_Absolute, vr::EVRScalarUnits::VRScalarUnits_NormalizedOneSided);
			vr::VRDriverInput()->CreateScalarComponent(m_ulPropertyContainer, "/input/grip/value", &HAnalogCtrlRight[11], vr::EVRScalarType::VRScalarType_Absolute, vr::EVRScalarUnits::VRScalarUnits_NormalizedOneSided);

			//  Buttons handles
			vr::VRDriverInput()->CreateBooleanComponent(m_ulPropertyContainer, "/input/a/click", &HButtonsCtrlRight[0]);
			vr::VRDriverInput()->CreateBooleanComponent(m_ulPropertyContainer, "/input/a/touch", &HButtonsCtrlRight[1]);
			vr::VRDriverInput()->CreateBooleanComponent(m_ulPropertyContainer, "/input/b/click", &HButtonsCtrlRight[2]);
			vr::VRDriverInput()->CreateBooleanComponent(m_ulPropertyContainer, "/input/b/touch", &HButtonsCtrlRight[3]);
			vr::VRDriverInput()->CreateBooleanComponent(m_ulPropertyContainer, "/input/system/click", &HButtonsCtrlRight[4]);
			vr::VRDriverInput()->CreateBooleanComponent(m_ulPropertyContainer, "/input/system/touch", &HButtonsCtrlRight[5]);

			vr::VRDriverInput()->CreateBooleanComponent(m_ulPropertyContainer, "/input/trackpad/touch", &HButtonsCtrlRight[6]);
			vr::VRDriverInput()->CreateBooleanComponent(m_ulPropertyContainer, "/input/trigger/click", &HButtonsCtrlRight[7]);
			vr::VRDriverInput()->CreateBooleanComponent(m_ulPropertyContainer, "/input/grip/touch", &HButtonsCtrlRight[8]);
			vr::VRDriverInput()->CreateBooleanComponent(m_ulPropertyContainer, "/input/thumbstick/click", &HButtonsCtrlRight[9]);
			vr::VRDriverInput()->CreateBooleanComponent(m_ulPropertyContainer, "/input/thumbstick/touch", &HButtonsCtrlRight[10]);

		}
		else{
			vr::VRProperties()->SetInt32Property(m_ulPropertyContainer, vr::Prop_ControllerRoleHint_Int32, vr::TrackedControllerRole_LeftHand);
			vr::VRProperties()->SetStringProperty(m_ulPropertyContainer, vr::Prop_ModelNumber_String, "Knuckles Left");
			vr::VRProperties()->SetStringProperty(m_ulPropertyContainer, vr::Prop_RenderModelName_String, "{indexcontroller}valve_controller_knu_1_0_Left");
			vr::VRProperties()->SetStringProperty(m_ulPropertyContainer, vr::Prop_Firmware_ProgrammingTarget_String, "LHR-E217CD00");
			vr::VRProperties()->SetStringProperty(m_ulPropertyContainer, vr::Prop_RegisteredDeviceType_String, "valve/index_controllerLHR-E217CD00");
			vr::VRProperties()->SetStringProperty(m_ulPropertyContainer, vr::Prop_NamedIconPathDeviceOff_String, "{indexcontroller}/icons/left_controller_status_off.png");
			vr::VRProperties()->SetStringProperty(m_ulPropertyContainer, vr::Prop_NamedIconPathDeviceSearching_String, "{indexcontroller}/icons/left_controller_status_searching.gif");
			vr::VRProperties()->SetStringProperty(m_ulPropertyContainer, vr::Prop_NamedIconPathDeviceSearchingAlert_String, "{indexcontroller}/icons//left_controller_status_searching_alert.gif");
			vr::VRProperties()->SetStringProperty(m_ulPropertyContainer, vr::Prop_NamedIconPathDeviceReady_String, "{indexcontroller}/icons//left_controller_status_ready.png");
			vr::VRProperties()->SetStringProperty(m_ulPropertyContainer, vr::Prop_NamedIconPathDeviceReadyAlert_String, "{indexcontroller}/icons//left_controller_status_ready_alert.png");
			vr::VRProperties()->SetStringProperty(m_ulPropertyContainer, vr::Prop_NamedIconPathDeviceNotReady_String, "{indexcontroller}/icons//left_controller_status_error.png");
			vr::VRProperties()->SetStringProperty(m_ulPropertyContainer, vr::Prop_NamedIconPathDeviceStandby_String, "{indexcontroller}/icons//left_controller_status_off.png");
			vr::VRProperties()->SetStringProperty(m_ulPropertyContainer, vr::Prop_NamedIconPathDeviceAlertLow_String, "{indexcontroller}/icons//left_controller_status_ready_low.png");
			vr::VRProperties()->SetStringProperty(m_ulPropertyContainer, vr::Prop_SerialNumber_String, "LHR-E217CD00");
			vr::VRDriverInput()->CreateSkeletonComponent(m_ulPropertyContainer, "/input/skeleton/left", "/skeleton/hand/left", "/pose/raw", vr::VRSkeletalTracking_Partial, nullptr, 0U, &m_skeletonHandle);
			


			vr::VRDriverInput()->CreateScalarComponent(m_ulPropertyContainer, "/input/thumbstick/x", &HAnalogCtrlLeft[0], vr::VRScalarType_Absolute, vr::VRScalarUnits_NormalizedTwoSided);
			vr::VRDriverInput()->CreateScalarComponent(m_ulPropertyContainer, "/input/thumbstick/y", &HAnalogCtrlLeft[1], vr::VRScalarType_Absolute, vr::VRScalarUnits_NormalizedTwoSided);
			vr::VRDriverInput()->CreateScalarComponent(m_ulPropertyContainer, "/input/trigger/value", &HAnalogCtrlLeft[2], vr::EVRScalarType::VRScalarType_Absolute, vr::EVRScalarUnits::VRScalarUnits_NormalizedOneSided);
			vr::VRDriverInput()->CreateScalarComponent(m_ulPropertyContainer, "/input/trackpad/x", &HAnalogCtrlLeft[3], vr::VRScalarType_Absolute, vr::VRScalarUnits_NormalizedTwoSided);
			vr::VRDriverInput()->CreateScalarComponent(m_ulPropertyContainer, "/input/trackpad/y", &HAnalogCtrlLeft[4], vr::VRScalarType_Absolute, vr::VRScalarUnits_NormalizedTwoSided);
			vr::VRDriverInput()->CreateScalarComponent(m_ulPropertyContainer, "/input/trackpad/force", &HAnalogCtrlLeft[5], vr::EVRScalarType::VRScalarType_Absolute, vr::EVRScalarUnits::VRScalarUnits_NormalizedOneSided);
			vr::VRDriverInput()->CreateScalarComponent(m_ulPropertyContainer, "/input/finger/index", &HAnalogCtrlLeft[6], vr::EVRScalarType::VRScalarType_Absolute, vr::EVRScalarUnits::VRScalarUnits_NormalizedOneSided);
			vr::VRDriverInput()->CreateScalarComponent(m_ulPropertyContainer, "/input/finger/middle", &HAnalogCtrlLeft[7], vr::EVRScalarType::VRScalarType_Absolute, vr::EVRScalarUnits::VRScalarUnits_NormalizedOneSided);
			vr::VRDriverInput()->CreateScalarComponent(m_ulPropertyContainer, "/input/finger/ring", &HAnalogCtrlLeft[8], vr::EVRScalarType::VRScalarType_Absolute, vr::EVRScalarUnits::VRScalarUnits_NormalizedOneSided);
			vr::VRDriverInput()->CreateScalarComponent(m_ulPropertyContainer, "/input/finger/pinky", &HAnalogCtrlLeft[9], vr::EVRScalarType::VRScalarType_Absolute, vr::EVRScalarUnits::VRScalarUnits_NormalizedOneSided);
			vr::VRDriverInput()->CreateScalarComponent(m_ulPropertyContainer, "/input/grip/force", &HAnalogCtrlLeft[10], vr::EVRScalarType::VRScalarType_Absolute, vr::EVRScalarUnits::VRScalarUnits_NormalizedOneSided);
			vr::VRDriverInput()->CreateScalarComponent(m_ulPropertyContainer, "/input/grip/value", &HAnalogCtrlLeft[11], vr::EVRScalarType::VRScalarType_Absolute, vr::EVRScalarUnits::VRScalarUnits_NormalizedOneSided);

			//  Buttons handles
			vr::VRDriverInput()->CreateBooleanComponent(m_ulPropertyContainer, "/input/a/click", &HButtonsCtrlLeft[0]);
			vr::VRDriverInput()->CreateBooleanComponent(m_ulPropertyContainer, "/input/a/touch", &HButtonsCtrlLeft[1]);
			vr::VRDriverInput()->CreateBooleanComponent(m_ulPropertyContainer, "/input/b/click", &HButtonsCtrlLeft[2]);
			vr::VRDriverInput()->CreateBooleanComponent(m_ulPropertyContainer, "/input/b/touch", &HButtonsCtrlLeft[3]);
			vr::VRDriverInput()->CreateBooleanComponent(m_ulPropertyContainer, "/input/system/click", &HButtonsCtrlLeft[4]);
			vr::VRDriverInput()->CreateBooleanComponent(m_ulPropertyContainer, "/input/system/touch", &HButtonsCtrlLeft[5]);

			vr::VRDriverInput()->CreateBooleanComponent(m_ulPropertyContainer, "/input/trackpad/touch", &HButtonsCtrlLeft[6]);
			vr::VRDriverInput()->CreateBooleanComponent(m_ulPropertyContainer, "/input/trigger/click", &HButtonsCtrlLeft[7]);
			vr::VRDriverInput()->CreateBooleanComponent(m_ulPropertyContainer, "/input/grip/touch", &HButtonsCtrlLeft[8]);
			vr::VRDriverInput()->CreateBooleanComponent(m_ulPropertyContainer, "/input/thumbstick/click", &HButtonsCtrlLeft[9]);
			vr::VRDriverInput()->CreateBooleanComponent(m_ulPropertyContainer, "/input/thumbstick/touch", &HButtonsCtrlLeft[10]);
		}


		
		vr::VRProperties()->SetBoolProperty(m_ulPropertyContainer, vr::Prop_Firmware_UpdateAvailable_Bool, false);
		vr::VRProperties()->SetBoolProperty(m_ulPropertyContainer, vr::Prop_Firmware_ManualUpdate_Bool, false);
		vr::VRProperties()->SetBoolProperty(m_ulPropertyContainer, vr::Prop_DeviceProvidesBatteryStatus_Bool, true);
		vr::VRProperties()->SetBoolProperty(m_ulPropertyContainer, vr::Prop_DeviceCanPowerOff_Bool, true);
		vr::VRProperties()->SetInt32Property(m_ulPropertyContainer, vr::Prop_DeviceClass_Int32, vr::TrackedDeviceClass_Controller);
		vr::VRProperties()->SetBoolProperty(m_ulPropertyContainer, vr::Prop_Firmware_ForceUpdateRequired_Bool, false);
		vr::VRProperties()->SetBoolProperty(m_ulPropertyContainer, vr::Prop_Identifiable_Bool, true);
		vr::VRProperties()->SetBoolProperty(m_ulPropertyContainer, vr::Prop_Firmware_RemindUpdate_Bool, false);
		vr::VRProperties()->SetInt32Property(m_ulPropertyContainer, vr::Prop_Axis0Type_Int32, vr::k_eControllerAxis_TrackPad);
		vr::VRProperties()->SetInt32Property(m_ulPropertyContainer, vr::Prop_Axis1Type_Int32, vr::k_eControllerAxis_Trigger);
		vr::VRProperties()->SetInt32Property(m_ulPropertyContainer, vr::Prop_Axis2Type_Int32, vr::k_eControllerAxis_Trigger);
		vr::VRProperties()->SetBoolProperty(m_ulPropertyContainer, vr::Prop_HasDisplayComponent_Bool, false);
		vr::VRProperties()->SetBoolProperty(m_ulPropertyContainer, vr::Prop_HasCameraComponent_Bool, false);
		vr::VRProperties()->SetBoolProperty(m_ulPropertyContainer, vr::Prop_HasDriverDirectModeComponent_Bool, false);
		vr::VRProperties()->SetBoolProperty(m_ulPropertyContainer, vr::Prop_HasVirtualDisplayComponent_Bool, false);
		vr::VRProperties()->SetInt32Property(m_ulPropertyContainer, vr::Prop_ControllerHandSelectionPriority_Int32, 0);
		vr::VRProperties()->SetStringProperty(m_ulPropertyContainer, vr::Prop_ManufacturerName_String, "Valve");
		vr::VRProperties()->SetStringProperty(m_ulPropertyContainer, vr::Prop_ResourceRoot_String, "indexcontroller");
		vr::VRProperties()->SetStringProperty(m_ulPropertyContainer, vr::Prop_InputProfilePath_String, "{indexcontroller}/input/index_controller_profile.json");
		vr::VRProperties()->SetStringProperty(m_ulPropertyContainer, vr::Prop_ControllerType_String, "knuckles");
		vr::VRProperties()->SetStringProperty(m_ulPropertyContainer, vr::Prop_TrackingSystemName_String, "lighthouse");

		// create our haptic component
		vr::VRDriverInput()->CreateHapticComponent(m_ulPropertyContainer, "/output/haptic", &haptic);

		break;

	case 1:
		if (contIndex == 1) 
		{
			vr::VRProperties()->SetInt32Property(m_ulPropertyContainer, vr::Prop_ControllerRoleHint_Int32, vr::TrackedControllerRole_RightHand);
			vr::VRProperties()->SetStringProperty(m_ulPropertyContainer, vr::Prop_RegisteredDeviceType_String,"htc/vive_controllerLHR-F94B3BD9");
			vr::VRProperties()->SetStringProperty(m_ulPropertyContainer, vr::Prop_SerialNumber_String, "LHR-F94B3BD9");

			vr::VRDriverInput()->CreateBooleanComponent(m_ulPropertyContainer, "/input/system/click", &HButtonsCtrlRight[0]);
			vr::VRDriverInput()->CreateBooleanComponent(m_ulPropertyContainer, "/input/trigger/click", &HButtonsCtrlRight[1]);
			vr::VRDriverInput()->CreateBooleanComponent(m_ulPropertyContainer, "/input/trackpad/touch", &HButtonsCtrlRight[2]);
			vr::VRDriverInput()->CreateBooleanComponent(m_ulPropertyContainer, "/input/trackpad/click", &HButtonsCtrlRight[3]);
			vr::VRDriverInput()->CreateBooleanComponent(m_ulPropertyContainer, "/input/grip/click", &HButtonsCtrlRight[4]);
			vr::VRDriverInput()->CreateBooleanComponent(m_ulPropertyContainer, "/input/application_menu/click", &HButtonsCtrlRight[5]);

			vr::VRDriverInput()->CreateScalarComponent(m_ulPropertyContainer, "/input/trigger/value", &HAnalogCtrlRight[0], vr::VRScalarType_Absolute, vr::VRScalarUnits_NormalizedOneSided);
			vr::VRDriverInput()->CreateScalarComponent(m_ulPropertyContainer, "/input/trackpad/x", &HAnalogCtrlRight[1], vr::VRScalarType_Absolute, vr::VRScalarUnits_NormalizedTwoSided);
			vr::VRDriverInput()->CreateScalarComponent(m_ulPropertyContainer, "/input/trackpad/y", &HAnalogCtrlRight[2], vr::VRScalarType_Absolute, vr::VRScalarUnits_NormalizedTwoSided);
		}
		else 
		{
			vr::VRProperties()->SetInt32Property(m_ulPropertyContainer, vr::Prop_ControllerRoleHint_Int32, vr::TrackedControllerRole_LeftHand);
			vr::VRProperties()->SetStringProperty(m_ulPropertyContainer, vr::Prop_RegisteredDeviceType_String, "htc/vive_controllerLHR-F94B3BD8");
			vr::VRProperties()->SetStringProperty(m_ulPropertyContainer, vr::Prop_SerialNumber_String, "LHR-F94B3BD8");

			vr::VRDriverInput()->CreateBooleanComponent(m_ulPropertyContainer, "/input/system/click", &HButtonsCtrlLeft[0]);
			vr::VRDriverInput()->CreateBooleanComponent(m_ulPropertyContainer, "/input/trigger/click", &HButtonsCtrlLeft[1]);
			vr::VRDriverInput()->CreateBooleanComponent(m_ulPropertyContainer, "/input/trackpad/touch", &HButtonsCtrlLeft[2]);
			vr::VRDriverInput()->CreateBooleanComponent(m_ulPropertyContainer, "/input/trackpad/click", &HButtonsCtrlLeft[3]);
			vr::VRDriverInput()->CreateBooleanComponent(m_ulPropertyContainer, "/input/grip/click", &HButtonsCtrlLeft[4]);
			vr::VRDriverInput()->CreateBooleanComponent(m_ulPropertyContainer, "/input/application_menu/click", &HButtonsCtrlLeft[5]);

			vr::VRDriverInput()->CreateScalarComponent(m_ulPropertyContainer, "/input/trigger/value", &HAnalogCtrlLeft[0], vr::VRScalarType_Absolute, vr::VRScalarUnits_NormalizedOneSided);
			vr::VRDriverInput()->CreateScalarComponent(m_ulPropertyContainer, "/input/trackpad/x", &HAnalogCtrlLeft[1], vr::VRScalarType_Absolute, vr::VRScalarUnits_NormalizedTwoSided);
			vr::VRDriverInput()->CreateScalarComponent(m_ulPropertyContainer, "/input/trackpad/y", &HAnalogCtrlLeft[2], vr::VRScalarType_Absolute, vr::VRScalarUnits_NormalizedTwoSided);
		}

		vr::VRProperties()->SetStringProperty(m_ulPropertyContainer, vr::Prop_TrackingSystemName_String, "lighthouse");
		
		vr::VRProperties()->SetBoolProperty(m_ulPropertyContainer, vr::Prop_WillDriftInYaw_Bool, false);
		vr::VRProperties()->SetBoolProperty(m_ulPropertyContainer, vr::Prop_DeviceIsWireless_Bool, true);
		vr::VRProperties()->SetBoolProperty(m_ulPropertyContainer, vr::Prop_DeviceIsCharging_Bool, false);
		vr::VRProperties()->SetBoolProperty(m_ulPropertyContainer, vr::Prop_Firmware_UpdateAvailable_Bool, false);
		vr::VRProperties()->SetBoolProperty(m_ulPropertyContainer, vr::Prop_Firmware_ManualUpdate_Bool, false);
		vr::VRProperties()->SetBoolProperty(m_ulPropertyContainer, vr::Prop_DeviceProvidesBatteryStatus_Bool, true);
		vr::VRProperties()->SetBoolProperty(m_ulPropertyContainer, vr::Prop_DeviceCanPowerOff_Bool, true);
		vr::VRProperties()->SetInt32Property(m_ulPropertyContainer, vr::Prop_DeviceClass_Int32, vr::TrackedDeviceClass_Controller);
		vr::VRProperties()->SetBoolProperty(m_ulPropertyContainer, vr::Prop_Firmware_ForceUpdateRequired_Bool, false);
		vr::VRProperties()->SetBoolProperty(m_ulPropertyContainer, vr::Prop_Identifiable_Bool, true);
		vr::VRProperties()->SetBoolProperty(m_ulPropertyContainer, vr::Prop_Firmware_RemindUpdate_Bool, false);
		vr::VRProperties()->SetInt32Property(m_ulPropertyContainer, vr::Prop_Axis0Type_Int32, vr::k_eControllerAxis_TrackPad);
		vr::VRProperties()->SetInt32Property(m_ulPropertyContainer, vr::Prop_Axis1Type_Int32, vr::k_eControllerAxis_Trigger);
		vr::VRProperties()->SetBoolProperty(m_ulPropertyContainer, vr::Prop_HasDisplayComponent_Bool, false);
		vr::VRProperties()->SetBoolProperty(m_ulPropertyContainer, vr::Prop_HasCameraComponent_Bool, false);
		vr::VRProperties()->SetBoolProperty(m_ulPropertyContainer, vr::Prop_HasDriverDirectModeComponent_Bool, false);
		vr::VRProperties()->SetBoolProperty(m_ulPropertyContainer, vr::Prop_HasVirtualDisplayComponent_Bool, false);
		vr::VRProperties()->SetInt32Property(m_ulPropertyContainer, vr::Prop_ControllerHandSelectionPriority_Int32, 0);
		vr::VRProperties()->SetStringProperty(m_ulPropertyContainer, vr::Prop_ModelNumber_String, "Vive. Controller MV");
		vr::VRProperties()->SetStringProperty(m_ulPropertyContainer, vr::Prop_RenderModelName_String, "vr_controller_vive_1_5");
		vr::VRProperties()->SetStringProperty(m_ulPropertyContainer, vr::Prop_ManufacturerName_String, "HTC");
		vr::VRProperties()->SetStringProperty(m_ulPropertyContainer, vr::Prop_ResourceRoot_String, "htc");

		vr::VRProperties()->SetStringProperty(m_ulPropertyContainer, vr::Prop_InputProfilePath_String, "{htc}/input/vive_controller_profile.json");
		vr::VRProperties()->SetStringProperty(m_ulPropertyContainer, vr::Prop_NamedIconPathDeviceOff_String, "{htc}/icons/controller_status_off.png");
		vr::VRProperties()->SetStringProperty(m_ulPropertyContainer, vr::Prop_NamedIconPathDeviceSearching_String, "{htc}/icons/controller_status_searching.gif");
		vr::VRProperties()->SetStringProperty(m_ulPropertyContainer, vr::Prop_NamedIconPathDeviceSearchingAlert_String, "{htc}/icons/controller_status_searching_alert.gif");
		vr::VRProperties()->SetStringProperty(m_ulPropertyContainer, vr::Prop_NamedIconPathDeviceReady_String, "{htc}/icons/controller_status_ready.png");
		vr::VRProperties()->SetStringProperty(m_ulPropertyContainer, vr::Prop_NamedIconPathDeviceReadyAlert_String, "{htc}/icons/controller_status_ready_alert.png");
		vr::VRProperties()->SetStringProperty(m_ulPropertyContainer, vr::Prop_NamedIconPathDeviceNotReady_String, "{htc}/icons/controller_status_error.png");
		vr::VRProperties()->SetStringProperty(m_ulPropertyContainer, vr::Prop_NamedIconPathDeviceStandby_String, "{htc}/icons/controller_status_off.png");
		vr::VRProperties()->SetStringProperty(m_ulPropertyContainer, vr::Prop_NamedIconPathDeviceAlertLow_String, "{htc}/icons/controller_status_ready_low.png");
		vr::VRProperties()->SetStringProperty(m_ulPropertyContainer, vr::Prop_ControllerType_String, "vive_controller");

		break;
	}
}


void updateController(int contType, int contIndex){

	switch (contType)
	{
	case 0:
		if (contIndex == 1) {

			vr::VRDriverInput()->UpdateBooleanComponent(HButtonsCtrlRight[0], (RightCtrl.Buttons & INDEX_AClick) != 0, 0);
			vr::VRDriverInput()->UpdateBooleanComponent(HButtonsCtrlRight[1], (RightCtrl.Buttons & INDEX_ATouch) != 0, 0);		//a button 
			vr::VRDriverInput()->UpdateBooleanComponent(HButtonsCtrlRight[2], (RightCtrl.Buttons & INDEX_BClick) != 0, 0);
			vr::VRDriverInput()->UpdateBooleanComponent(HButtonsCtrlRight[3], (RightCtrl.Buttons & INDEX_BTouch) != 0, 0);		//b button
			vr::VRDriverInput()->UpdateBooleanComponent(HButtonsCtrlRight[4], (RightCtrl.Buttons & INDEX_SYSClick) != 0, 0);
			vr::VRDriverInput()->UpdateBooleanComponent(HButtonsCtrlRight[5], (RightCtrl.Buttons & INDEX_SYSClick) != 0, 0);	//sys button
			vr::VRDriverInput()->UpdateBooleanComponent(HButtonsCtrlRight[6], (RightCtrl.Buttons & INDEX_TrackpadTouch) != 0, 0);	//trackpad touch
			vr::VRDriverInput()->UpdateBooleanComponent(HButtonsCtrlRight[7], (RightCtrl.Trigger), 0);							//trigger click
			vr::VRDriverInput()->UpdateBooleanComponent(HButtonsCtrlRight[8], (RightCtrl.Buttons & INDEX_FingerMiddle) != 0, 0);	//grip touch
			vr::VRDriverInput()->UpdateBooleanComponent(HButtonsCtrlRight[9], (RightCtrl.Buttons & INDEX_ThumbStickClick) != 0, 0);
			vr::VRDriverInput()->UpdateBooleanComponent(HButtonsCtrlRight[10], (RightCtrl.Buttons & INDEX_ThumbStickTouch) != 0, 0); //joy touch and click

			//analog stuff
			vr::VRDriverInput()->UpdateScalarComponent(HAnalogCtrlRight[0], RightCtrl.JoyAxisX, 0); //joyx
			vr::VRDriverInput()->UpdateScalarComponent(HAnalogCtrlRight[1], RightCtrl.JoyAxisY, 0); //joyy
			vr::VRDriverInput()->UpdateScalarComponent(HAnalogCtrlRight[2], RightCtrl.Trigger, 0);	//Trigger
			vr::VRDriverInput()->UpdateScalarComponent(HAnalogCtrlRight[3], 0, 0); //Trackpad x
			vr::VRDriverInput()->UpdateScalarComponent(HAnalogCtrlRight[4], RightCtrl.TrackpY, 0); //Trackpad Y

			

			vr::VRDriverInput()->UpdateScalarComponent(HAnalogCtrlRight[6], ((RightCtrl.Buttons & INDEX_FingerIndex) != 0), 0); //Index
			vr::VRDriverInput()->UpdateScalarComponent(HAnalogCtrlRight[7], ((RightCtrl.Buttons & INDEX_FingerMiddle) != 0), 0); //middle
			vr::VRDriverInput()->UpdateScalarComponent(HAnalogCtrlRight[8], ((RightCtrl.Buttons & INDEX_FingerRing) != 0), 0); //Ring
			vr::VRDriverInput()->UpdateScalarComponent(HAnalogCtrlRight[9], ((RightCtrl.Buttons & INDEX_FingerPinky) != 0), 0); //Pinky

			if ((RightCtrl.Buttons & INDEX_TrackpadTouch) != 0) {
				vr::VRDriverInput()->UpdateScalarComponent(HAnalogCtrlRight[5], 1.f, 0); //Trackpad force
				vr::VRDriverInput()->UpdateScalarComponent(HAnalogCtrlRight[4], RightCtrl.TrackpY, 0); //Trackpad Y
				vr::VRDriverInput()->UpdateScalarComponent(HAnalogCtrlRight[3], 0.f, 0); //Trackpad X
			}
			else {
				vr::VRDriverInput()->UpdateScalarComponent(HAnalogCtrlRight[5], 0.f, 0); //Trackpad force
			}

			if ((RightCtrl.Buttons & INDEX_FingerMiddle) != 0) {
				vr::VRDriverInput()->UpdateScalarComponent(HAnalogCtrlRight[10], 0.5f, 0); //grip force
				vr::VRDriverInput()->UpdateScalarComponent(HAnalogCtrlRight[11], 0.5f, 0); //grip value

				if ((RightCtrl.Buttons & INDEX_FingerRing) != 0) {
					vr::VRDriverInput()->UpdateScalarComponent(HAnalogCtrlRight[10], 0.75f, 2); //grip force
					vr::VRDriverInput()->UpdateScalarComponent(HAnalogCtrlRight[11], 0.75f, 2); //grip value

					if ((RightCtrl.Buttons & INDEX_FingerPinky) != 0) {
						vr::VRDriverInput()->UpdateScalarComponent(HAnalogCtrlRight[10], 1.f, 5); //grip force
						vr::VRDriverInput()->UpdateScalarComponent(HAnalogCtrlRight[11], 1.f, 5); //grip value
					}
				}
			}
			else {
				vr::VRDriverInput()->UpdateScalarComponent(HAnalogCtrlRight[10], 0.f, 0); //grip force
				vr::VRDriverInput()->UpdateScalarComponent(HAnalogCtrlRight[11], 0.f, 0); //grip value
			}
		}
		else
		{
			//Controller2
			vr::VRDriverInput()->UpdateBooleanComponent(HButtonsCtrlLeft[0], (LeftCtrl.Buttons & INDEX_AClick) != 0, 0);
			vr::VRDriverInput()->UpdateBooleanComponent(HButtonsCtrlLeft[1], (LeftCtrl.Buttons & INDEX_ATouch) != 0, 0);
			vr::VRDriverInput()->UpdateBooleanComponent(HButtonsCtrlLeft[2], (LeftCtrl.Buttons & INDEX_BClick) != 0, 0);
			vr::VRDriverInput()->UpdateBooleanComponent(HButtonsCtrlLeft[3], (LeftCtrl.Buttons & INDEX_BTouch) != 0, 0);
			vr::VRDriverInput()->UpdateBooleanComponent(HButtonsCtrlLeft[4], (LeftCtrl.Buttons & INDEX_SYSClick) != 0, 0);
			vr::VRDriverInput()->UpdateBooleanComponent(HButtonsCtrlLeft[5], (LeftCtrl.Buttons & INDEX_SYSClick) != 0, 0);
			vr::VRDriverInput()->UpdateBooleanComponent(HButtonsCtrlLeft[6], (LeftCtrl.Buttons & INDEX_TrackpadTouch) != 0, 0);
			vr::VRDriverInput()->UpdateBooleanComponent(HButtonsCtrlLeft[7], (LeftCtrl.Trigger), 0);
			vr::VRDriverInput()->UpdateBooleanComponent(HButtonsCtrlLeft[8], (LeftCtrl.Buttons & INDEX_FingerMiddle) != 0, 0);
			vr::VRDriverInput()->UpdateBooleanComponent(HButtonsCtrlLeft[9], (LeftCtrl.Buttons & INDEX_ThumbStickClick) != 0, 0);
			vr::VRDriverInput()->UpdateBooleanComponent(HButtonsCtrlLeft[10], (LeftCtrl.Buttons & INDEX_ThumbStickTouch) != 0, 0);

			//analog stuff
			vr::VRDriverInput()->UpdateScalarComponent(HAnalogCtrlLeft[0], LeftCtrl.JoyAxisX, 0); //joyx
			vr::VRDriverInput()->UpdateScalarComponent(HAnalogCtrlLeft[1], LeftCtrl.JoyAxisY, 0); //joyy
			vr::VRDriverInput()->UpdateScalarComponent(HAnalogCtrlLeft[2], LeftCtrl.Trigger, 0);	//Trigger
			vr::VRDriverInput()->UpdateScalarComponent(HAnalogCtrlLeft[3], 0, 0); //Trackpad x
			vr::VRDriverInput()->UpdateScalarComponent(HAnalogCtrlLeft[4], 0, 0); //Trackpad Y

			vr::VRDriverInput()->UpdateScalarComponent(HAnalogCtrlLeft[6], ((LeftCtrl.Buttons & INDEX_FingerIndex) != 0), 0); //Index
			vr::VRDriverInput()->UpdateScalarComponent(HAnalogCtrlLeft[7], ((LeftCtrl.Buttons & INDEX_FingerMiddle) != 0), 0); //middle
			vr::VRDriverInput()->UpdateScalarComponent(HAnalogCtrlLeft[8], ((LeftCtrl.Buttons & INDEX_FingerRing) != 0), 0); //Ring
			vr::VRDriverInput()->UpdateScalarComponent(HAnalogCtrlLeft[9], ((LeftCtrl.Buttons & INDEX_FingerPinky) != 0), 0); //Pinky

			if ((LeftCtrl.Buttons & INDEX_TrackpadTouch) != 0) {
				vr::VRDriverInput()->UpdateScalarComponent(HAnalogCtrlLeft[5], 1.f, 0); //Trackpad force
				vr::VRDriverInput()->UpdateScalarComponent(HAnalogCtrlLeft[4], LeftCtrl.TrackpY, 0); //Trackpad Y
				vr::VRDriverInput()->UpdateScalarComponent(HAnalogCtrlLeft[3], 0.0f, 0); //Trackpad X
			}
			else {
				vr::VRDriverInput()->UpdateScalarComponent(HAnalogCtrlLeft[5], 0.f, 0); //Trackpad force
			}

			if ((LeftCtrl.Buttons & INDEX_FingerMiddle) != 0) {
				vr::VRDriverInput()->UpdateScalarComponent(HAnalogCtrlLeft[10], 0.5f, 0); //grip force
				vr::VRDriverInput()->UpdateScalarComponent(HAnalogCtrlLeft[11], 0.5f, 0); //grip value

				if ((LeftCtrl.Buttons & INDEX_FingerRing) != 0) {
					vr::VRDriverInput()->UpdateScalarComponent(HAnalogCtrlLeft[10], 0.75f, 2); //grip force
					vr::VRDriverInput()->UpdateScalarComponent(HAnalogCtrlLeft[11], 0.75f, 2); //grip value

					if ((LeftCtrl.Buttons & INDEX_FingerPinky) != 0) {
						vr::VRDriverInput()->UpdateScalarComponent(HAnalogCtrlLeft[10], 1.f, 5); //grip force
						vr::VRDriverInput()->UpdateScalarComponent(HAnalogCtrlLeft[11], 1.f, 5); //grip value
					}
				}
			}
			else {
				vr::VRDriverInput()->UpdateScalarComponent(HAnalogCtrlLeft[10], 0.f, 0); //grip force
				vr::VRDriverInput()->UpdateScalarComponent(HAnalogCtrlLeft[11], 0.f, 0); //grip value
			}
		}

		if ((LeftCtrl.Buttons & INDEX_ThumbStickClick) != 0 && (RightCtrl.Buttons & INDEX_ThumbStickClick) != 0 && (LeftCtrl.Trigger > 0.9f) && (RightCtrl.Trigger > 0.9f))
		{
			dH.SetCentering();
		}
		break;



	case 1:
		if (contIndex == 1) 
		{
			vr::VRDriverInput()->UpdateBooleanComponent(HButtonsCtrlRight[0], (RightCtrl.Buttons& HTC_SysClick) != 0, 0);
			vr::VRDriverInput()->UpdateBooleanComponent(HButtonsCtrlRight[2], (RightCtrl.Buttons& HTC_ThumbstickTouch) != 0, 0);
			vr::VRDriverInput()->UpdateBooleanComponent(HButtonsCtrlRight[3], (RightCtrl.Buttons& HTC_ThumbstickClick) != 0, 0);
			vr::VRDriverInput()->UpdateBooleanComponent(HButtonsCtrlRight[4], (RightCtrl.Buttons& HTC_GripClick) != 0, 0);
			vr::VRDriverInput()->UpdateBooleanComponent(HButtonsCtrlRight[5], (RightCtrl.Buttons& HTC_MenuClick) != 0, 0);

			vr::VRDriverInput()->UpdateScalarComponent(HAnalogCtrlRight[0], RightCtrl.Trigger, 0); 
			vr::VRDriverInput()->UpdateScalarComponent(HAnalogCtrlRight[1], RightCtrl.JoyAxisX, 0); 
			vr::VRDriverInput()->UpdateScalarComponent(HAnalogCtrlRight[2], RightCtrl.JoyAxisY, 0);	

			if (RightCtrl.Trigger > 0.9f)
			{
				vr::VRDriverInput()->UpdateBooleanComponent(HButtonsCtrlRight[1], 1 != 0, 0);
			}
			else
			{
				vr::VRDriverInput()->UpdateBooleanComponent(HButtonsCtrlRight[1], 0 != 0, 0);
			}

		}
		else
		{
			vr::VRDriverInput()->UpdateBooleanComponent(HButtonsCtrlLeft[0], (LeftCtrl.Buttons& HTC_SysClick) != 0, 0);
			vr::VRDriverInput()->UpdateBooleanComponent(HButtonsCtrlLeft[2], (LeftCtrl.Buttons& HTC_ThumbstickTouch) != 0, 0);
			vr::VRDriverInput()->UpdateBooleanComponent(HButtonsCtrlLeft[3], (LeftCtrl.Buttons& HTC_ThumbstickClick) != 0, 0);
			vr::VRDriverInput()->UpdateBooleanComponent(HButtonsCtrlLeft[4], (LeftCtrl.Buttons& HTC_GripClick) != 0, 0);
			vr::VRDriverInput()->UpdateBooleanComponent(HButtonsCtrlLeft[5], (LeftCtrl.Buttons& HTC_MenuClick) != 0, 0);

			vr::VRDriverInput()->UpdateScalarComponent(HAnalogCtrlLeft[0], LeftCtrl.Trigger, 0);
			vr::VRDriverInput()->UpdateScalarComponent(HAnalogCtrlLeft[1], LeftCtrl.JoyAxisX, 0);
			vr::VRDriverInput()->UpdateScalarComponent(HAnalogCtrlLeft[2], LeftCtrl.JoyAxisY, 0);

			if (LeftCtrl.Trigger > 0.9f) 
			{
				vr::VRDriverInput()->UpdateBooleanComponent(HButtonsCtrlLeft[1], 1 != 0, 0);
			}
			else 
			{
				vr::VRDriverInput()->UpdateBooleanComponent(HButtonsCtrlLeft[1], 0 != 0, 0);
			}

		}

		if ((LeftCtrl.Buttons & HTC_ThumbstickClick) != 0 && (RightCtrl.Buttons & HTC_ThumbstickClick) != 0 && (LeftCtrl.Trigger > 0.9f) && (RightCtrl.Trigger > 0.9f))
		{
			dH.SetCentering();
		}

		break;
	}
}


std::string getCtrlSerial(int contType, int contIndex) {
	
	switch (contType) 
	{
	case 0:
		if (contIndex == 1) {
			return "LHR-E217CD01";
		}
		else
		{
			return "LHR-E217CD00";
		}
		break;
	case 1:
		if (contIndex == 1) {
			return "LHR-F94B3BD9";
		}
		else 
		{
			return "LHR-F94B3BD8";
		}
		break;
	}
}


#endif