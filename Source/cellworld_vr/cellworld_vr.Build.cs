// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class cellworld_vr : ModuleRules
{
	public cellworld_vr(ReadOnlyTargetRules Target) : base(Target)
	{
		
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { 
            "Core", "CoreUObject", "HeadMountedDisplay", "Engine", "InputCore", 
            "EyeTracker","InputCore","UMG","NavigationSystem","HPGlia",
            "TCPMessages", "ExperimentPlugin", "AIModule", "GameplayTasks",
            "Json", "JsonUtilities", "AsyncLoadingScreen"
        });
        PrivateDependencyModuleNames.AddRange(new string[] { /*"HeadMountedDisplay",*/ "Slate", "SlateCore" });

        PublicIncludePaths.AddRange(new string[] {
            "cellworld_vr/PredatorController",
            //"cellworld_vr/Public",
            "AsyncLoadingScreen/AsyncLoadingScreenLibrary.h"
        });
        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
    }
}
