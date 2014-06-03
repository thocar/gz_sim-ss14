#ifndef _HOMEWORK2_H_
#define _HOMEWORK2_H_

#include "gazebo/physics/physics.hh"
#include "gazebo/gazebo.hh"

namespace gazebo
{
	class Homework2 : public WorldPlugin
	{

		public: void Load(physics::WorldPtr _world, sdf::ElementPtr _sdf);
		/// \brief Callback method for updateConnection_, is called in every world update.
		/// In this callback a joint between "sphere1" and "sphere1_0" created. The objects "sphere1" get some velocity to move.
		/// After some time the joint will be removed
		public: void OnUpdate(const common::UpdateInfo & /*_info*/);

		/// \brief This method initializes the plugin. At first the method gets acces to the current world and print the name.
		/// Then the method gets acces to the physics engine and print out them too.
		/// At last the methods subscribes on event::Events::ConnectWorldUpdateBegin.
		private: virtual void Init();
		
		// attribute to update
		private: event::ConnectionPtr _updateConnection;
		// world ptr
		private: physics::WorldPtr _world;
		// physics engine ptr
		private: physics::PhysicsEnginePtr _phy_eng;
		// start time
		private: common::Time _st_time;
		// set link already?
		private: bool _set_link;
		// remove link already?
		private: bool _removed_link;
		// the joint
		private: physics::JointPtr _joint_ptr;

	};
	// Register this plugin with the simulator
	GZ_REGISTER_WORLD_PLUGIN(Homework2)
}

#endif