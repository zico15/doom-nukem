#include <DoomEngine.h>

static void init(char *wad_path)
{
    doomEngine()->wad_path = string().copy(wad_path);
    WADData()->init(doomEngine()->wad_path);
}

t_doomEngine *doomEngine()
{
    static t_doomEngine e = {
        NULL,
        init,
    };

    return (&e);
}