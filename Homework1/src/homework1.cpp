#include "gazebo/physics/physics.hh"
#include "gazebo/common/common.hh"
#include "gazebo/gazebo.hh"

namespace gazebo
{
  class Homework1Plugin : public SystemPlugin
  {
    public: virtual ~Homework1Plugin()
    {

    }

    public: virtual void Load(int /*_argc*/, char ** /*_argv*/)
    {
    }

    private: virtual void Init()
    {
      physics::WorldPtr parent = physics::get_world();
      std::string name = parent->GetName();
      std::cout << "World Name: " << name;
    }

  };

  // Register this plugin with the simulator
  GZ_REGISTER_SYSTEM_PLUGIN(Homework1Plugin)
}