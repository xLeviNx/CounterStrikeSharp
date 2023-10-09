#pragma clang diagnostic push
#pragma ide diagnostic ignored "readability-identifier-naming"
/**
 * vim: set ts=4 sw=4 tw=99 noet :
 * ======================================================
 * Metamod:Source Sample Plugin
 * Written by AlliedModders LLC.
 * ======================================================
 *
 * This software is provided 'as-is', without any express or implied warranty.
 * In no event will the authors be held liable for any damages arising from
 * the use of this software.
 *
 * This sample plugin is public domain.
 */

#ifndef _INCLUDE_METAMOD_SOURCE_STUB_PLUGIN_H_
#define _INCLUDE_METAMOD_SOURCE_STUB_PLUGIN_H_

#include <ISmmPlugin.h>
#include <functional>
#include <igameevents.h>
#include <iplayerinfo.h>
#include <sh_vector.h>
#include <vector>

namespace counterstrikesharp
{
class CounterStrikeSharpMMPlugin : public ISmmPlugin, public IMetamodListener
{
  public:
    bool Load(PluginId id, ISmmAPI *ismm, char *error, size_t maxlen, bool late) override;
    bool Unload(char *error, size_t maxlen) override;
    bool Pause(char *error, size_t maxlen) override;
    bool Unpause(char *error, size_t maxlen) override;
    void AllPluginsLoaded() override;

  public: // hooks
    void OnLevelInit(char const *pMapName, char const *pMapEntities, char const *pOldLevel, char const *pLandmarkName,
                     bool loadGame, bool background) override;
    void OnLevelShutdown() override;
    void Hook_GameFrame(bool simulating, bool bFirstTick, bool bLastTick);
    void AddTaskForNextFrame(std::function<void()> &&task);

  public:
    const char *GetAuthor() override;
    const char *GetName() override;
    const char *GetDescription() override;
    const char *GetURL() override;
    const char *GetLicense() override;
    const char *GetVersion() override;
    const char *GetDate() override;
    const char *GetLogTag() override;

  private:
    std::vector<std::function<void()>> m_nextTasks;
};

extern CounterStrikeSharpMMPlugin gPlugin;

PLUGIN_GLOBALVARS();

#endif //_INCLUDE_METAMOD_SOURCE_STUB_PLUGIN_H_

#pragma clang diagnostic pop
}