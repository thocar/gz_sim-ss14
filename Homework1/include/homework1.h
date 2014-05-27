#ifndef _HOMEWORK1_H_
#define _HOMEWORK1_H_

#include "gazebo/physics/physics.hh"
#include "gazebo/gazebo.hh"

namespace gazebo
{
	class Homework1 : public SystemPlugin
	{

		public: virtual void Load(int /*_argc*/, char ** /*_argv*/);
		/// \brief Callback method for updateConnection_, is called in every world update.
		/// In this callback the objects "box1" and "sphere1" get some velocities to move.
		public: void OnUpdate(const common::UpdateInfo & /*_info*/);

		/// \brief This method initializes the plugin. At first the method gets acces to the current world and print the name.
		/// Then the method gets acces to the physics engine and print out them too.
		/// At last the methods subscribes on event::Events::ConnectWorldUpdateBegin.
		private: virtual void Init();
		
		// attribute to update
		private: event::ConnectionPtr _updateConnection;
		// world ptr
		private: physics::WorldPtr _world;
		// world name
		private: std::string _world_name;
		// physics engine ptr
		private: physics::PhysicsEnginePtr _phy_eng;
		// physics engine name
		private: std::string _phy_eng_name;
		// model count
		private: int _model_count;

	};
	// Register this plugin with the simulator
	GZ_REGISTER_SYSTEM_PLUGIN(Homework1)
}

#endif