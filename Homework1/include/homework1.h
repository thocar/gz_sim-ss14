#ifndef HOMEWORK1
#define HOMEWORK1

#include "gazebo/physics/physics.hh"
#include "gazebo/gazebo.hh"

namespace gazebo
{
class Homework1 : public SystemPlugin
{

public:
    virtual void Load(int /*_argc*/, char ** /*_argv*/);
    void OnUpdate(const common::UpdateInfo & /*_info*/);

private:
    virtual void Init();
    event::ConnectionPtr updateConnection_;
    std::string world_name_;
    physics::WorldPtr world_;
    physics::PhysicsEnginePtr phy_eng_;
    std::string phy_eng_name_;
    int model_count_;

};
// Register this plugin with the simulator
GZ_REGISTER_SYSTEM_PLUGIN(Homework1)
}

#endif