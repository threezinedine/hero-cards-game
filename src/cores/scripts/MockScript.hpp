#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <utils/configuration/ConfigurableObject.hpp>
#include "IScript.hpp"

using namespace ntt;

class MockScript : public IScript
{
public:
    inline sid_t GetScriptID() const { return m_ScriptID; };
    inline void SetScriptID(sid_t id) { m_ScriptID = id; };

    MOCK_METHOD(void, Load, ());
    MOCK_METHOD(void, Update, (void *, float));
    MOCK_METHOD(void, Unload, ());
    MOCK_METHOD(void, LoadConfigure, (ConfigurableObject &), (override));

private:
    sid_t m_ScriptID;
};
