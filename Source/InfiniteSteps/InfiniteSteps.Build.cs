// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class InfiniteSteps : ModuleRules
{
	public InfiniteSteps(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "UMG", "SlateCore" });
	}
}
