#pragma once
#include "math/VMatrix.hpp"
#include "math/Vector.hpp"
#include "IMaterialSystem.hpp"
#include <array>
#include <tuple>


enum OverrideType_t
{
    Normal = 0,
    BuildShadows,
    DepthWrite,
    CustomMaterial, // skin change
    SsaoDepthWrite
};

enum MaterialVarFlags_t
{
    MATERIAL_VAR_DEBUG = (1 << 0),
    MATERIAL_VAR_NO_DEBUG_OVERRIDE = (1 << 1),
    MATERIAL_VAR_NO_DRAW = (1 << 2),
    MATERIAL_VAR_USE_IN_FILLRATE_MODE = (1 << 3),
    MATERIAL_VAR_VERTEXCOLOR = (1 << 4),
    MATERIAL_VAR_VERTEXALPHA = (1 << 5),
    MATERIAL_VAR_SELFILLUM = (1 << 6),
    MATERIAL_VAR_ADDITIVE = (1 << 7),
    MATERIAL_VAR_ALPHATEST = (1 << 8),
    //MATERIAL_VAR_UNUSED = (1 << 9),
    MATERIAL_VAR_ZNEARER = (1 << 10),
    MATERIAL_VAR_MODEL = (1 << 11),
    MATERIAL_VAR_FLAT = (1 << 12),
    MATERIAL_VAR_NOCULL = (1 << 13),
    MATERIAL_VAR_NOFOG = (1 << 14),
    MATERIAL_VAR_IGNOREZ = (1 << 15),
    MATERIAL_VAR_DECAL = (1 << 16),
    MATERIAL_VAR_ENVMAPSPHERE = (1 << 17), // OBSOLETE
    MATERIAL_VAR_UNUSED = (1 << 18), // UNUSED
    MATERIAL_VAR_ENVMAPCAMERASPACE = (1 << 19), // OBSOLETE
    MATERIAL_VAR_BASEALPHAENVMAPMASK = (1 << 20),
    MATERIAL_VAR_TRANSLUCENT = (1 << 21),
    MATERIAL_VAR_NORMALMAPALPHAENVMAPMASK = (1 << 22),
    MATERIAL_VAR_NEEDS_SOFTWARE_SKINNING = (1 << 23), // OBSOLETE
    MATERIAL_VAR_OPAQUETEXTURE = (1 << 24),
    MATERIAL_VAR_ENVMAPMODE = (1 << 25), // OBSOLETE
    MATERIAL_VAR_SUPPRESS_DECALS = (1 << 26),
    MATERIAL_VAR_HALFLAMBERT = (1 << 27),
    MATERIAL_VAR_WIREFRAME = (1 << 28),
    MATERIAL_VAR_ALLOWALPHATOCOVERAGE = (1 << 29),
    MATERIAL_VAR_ALPHA_MODIFIED_BY_PROXY = (1 << 30),
    MATERIAL_VAR_VERTEXFOG = (1 << 31),
};

class IMaterialVar;

class IMaterial
{
public:
    VFUNC(const char*, getName, 0, (), (this));
    VFUNC(const char*, getTextureGroupName, 1, (), (this));
    VFUNC(IMaterialVar*, findVar, 11, (const char* name, bool* found = nullptr, bool complain = true), (this, name, found, complain));
    VFUNC(void, alphaModulate, 27, (float alpha), (this, alpha));   
    VFUNC(void, colorModulate, 28, (float r, float g, float b), (this, r, g, b));
    VFUNC(void, colorModulate, 28, (Color color), (this, color.rDevided(), color.gDevided(), color.bDevided()));
   /* void colorModulate(Color color)
    {
        colorModulate(color.rDevided(), color.gDevided(), color.bDevided());
        alphaModulate(color.aDevided());
    }*/
    VFUNC(void, setMaterialVarFlag, 29, (MaterialVarFlags_t flag, bool on), (this, flag, on));
    VFUNC(bool, isError, 42, (), (this));
};


class IMaterialVar
{
public:
    VFUNC(void, setValue, 4, (float val), (this, val));
    VFUNC(void, setValues, 5, (int val), (this, val));
    VFUNC(void, setValues, 6, (const char* val), (this, val));
    VFUNC(void, setValues, 11, (Vector val), (this, val));
};