// BladeMode.Build.cs

using UnrealBuildTool;

public class BladeMode : ModuleRules
{
    public BladeMode(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine",
            "ProceduralMeshComponent"
            });
    }
}