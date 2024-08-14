#pragma once
#include <cores/commons/common.hpp>
#include <cores/interfaces/interfaces.hpp>

namespace ntt
{
    class Entity;

    class Script : public IRenderable, public Loadable, public IConfigurable
    {
    public:
        Script(sid_t scriptId);
        Script(sid_t scriptId, Entity *entity);
        virtual ~Script();

        void Load() override;
        void Update(float delta) override;
        void Render() override;
        void Unload() override;

        void LoadConfigure(JSON config) override;

        inline sid_t GetScriptID() const { return m_ScriptID; }
        inline void SetEntity(Entity *entity) { m_Entity = entity; }

    protected:
        virtual void LoadImpl();
        virtual void UpdateImpl(float delta);
        virtual void RenderImpl();
        virtual void UnloadImpl();

        virtual void LoadConfigureImpl(JSON config);

        inline Entity *GetEntity() const { return m_Entity; }

    private:
        sid_t m_ScriptID;
        Entity *m_Entity;
    };
} // namespace ntt
