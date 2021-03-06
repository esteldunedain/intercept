/*!
@file
@author Verox (verox.averre@gmail.com)
@author Nou (korewananda@gmail.com)
@author Glowbal (thomasskooi@live.nl)

@brief Uncategorized

Lacking a specific category or have not been assigned to a category yet.

Similar to misc.hpp but not... Kind of... These are both a mess.

https://github.com/NouberNou/intercept
*/
#pragma once
#include "shared.hpp"
#include "client\client.hpp"
#include "shared\client_types.hpp"

using namespace intercept::types;

namespace intercept {
	namespace sqf {
		struct rv_bounding_box
		{
			vector3 min;
			vector3 max;
		};

		struct rv_container
		{
			std::string type;
			object container;
		};

		struct rv_destination
		{
			vector3 pos;
			std::string planning_mode;
			bool force_replan;
		};

		struct rv_crew_member
		{
			object unit;
			std::string role;
			float cargo_index;
			// turret path; // TODO
			bool person_turret;
		};

		struct rv_color
		{
			float red;
			float blue;
			float green;
			float alpha;

			std::vector<game_value> __to_gv_vector() const
			{
				return std::vector<game_value> ({
					red,
					blue,
					green,
					alpha
				});
			}

		};

        void draw_line_3d(const vector3 &pos1_, const vector3 &pos2_, const rv_color &color_);
        void draw_icon_3d(const std::string &texture_, const rv_color &color_, const vector3 &pos_agl_, float width_, float height_, float angle_, const std::string &text_ = "", float shadow_ = 1.0f, float text_size_ = 1.0f, const std::string &font_ = "TahomaB" );

        vector3 vector_dir(const object & obj_);
        vector3 vector_dir_visual(const object & obj_);
        vector3 selection_positon(const object & obj_, const std::string & selection_name_);

        rv_game_value get_variable(const rv_namespace &namespace_, const std::string &var_name_);

        vector3 model_to_world_visual(const object &model_, const vector3 &model_pos_);

        vector2 world_to_screen(const vector3 &pos_agl_);
        vector2 world_to_screen(const vector3 &pos_agl_, bool &in_screen_);

        void ctrl_set_position(const control &ctrl_, float x_, float y_, float width_, float height_);
        void ctrl_map_anim_add(const control &ctrl_, float time_, float zoom_, vector2 pos_);
        vector2 ctrl_map_screen_to_world(const control &ctrl_, const vector2 &screen_pos_);

        std::vector<object> near_entities(const vector3 &pos_agl_, const std::vector<std::string> &types_, float range_);

        void set_vector_dir(const object &obj_, const vector3 &vec_);
        void set_velocity(const object &obj_, const vector3 &vel_);

        object create_vehicle_local(const std::string &type_, const vector3 &pos_atl_);

        void draw_rectangle(const control &ctrl_, const vector2 center_pos_, float a_, float b_, float angle_, const rv_color &color_, const std::string &fill_texture_);
        
        //@TODO: draw_icon could stand to have a few enums probably for arguments like shadow and align.
        void draw_icon(const control &ctrl_, const std::string &texture_, const rv_color &color_, const vector2 &pos_, float width_, float height_, float angle_, const std::string &text_, uint32_t shadow_, float text_size_, const std::string &font_, const std::string &align_);
        void draw_icon(const control &ctrl_, const std::string &texture_, const rv_color &color_, const object &pos_, float width_, float height_, float angle_, const std::string &text_, uint32_t shadow_, float text_size_, const std::string &font_, const std::string &align_);

        vector3 velocity(const object &obj_);

		/* potential namespace: */
		std::vector<std::string> action_keys(const std::string &user_action_);

		rv_text action_keys_images(const std::string &user_action_);
		std::string action_keys_names(const std::string &user_action_);
		std::string action_keys_names(const std::string &user_action_, int max_keys_);
		std::string action_keys_names(const std::string &user_action_, int max_keys_, const std::string &input_device_priority_);

		std::vector<std::string> action_keys_names_array(const std::string &user_action_);
		std::vector<std::string> action_keys_names_array(const std::string &user_action_, int max_keys_);
		std::vector<std::string> action_keys_names_array(const std::string &user_action_, int max_keys_, const std::string &input_device_priority_);

		/* potential namespace: misc, missions */
		void activate_addons(std::vector<std::string> &addons_);

		/* potential namespace: camera */
		void add_cam_shake(float power_, float duration_, float frequency_);

		/* potential namespace: items, inventory, campaign */
		void add_item_pool(const std::string &item_name_, int item_count_);
		void add_magazine_pool(const std::string &mag_name_, int mag_count_);

		/* potential namespace: core, misc, world */
		void add_to_remains_collector(std::vector<object> objects_);

		/* potential namespace: medical, misc, unit */
		void ais_finish_heal(const object &wounded_, const object &medic_, bool medic_can_heal_);

		/* potential namespace: core, all */
		std::vector<object> all_mission_objects(const std::string &type_);

		/* potential namespace: vehicle, core, cargo */
		std::vector<object> assigned_cargo(const object &veh_);
		std::vector<std::string> assigned_items(const object &unit_);

		/* potential namespace: misc, attach */
		object attached_object(const location &loc_);
		std::vector<object> attached_objects(const object &obj_);
		object attached_to(const object &obj_);

		/* potential namespace: ai */
		bool attack_enabled(const object &unit_);
		bool attack_enabled(const group &group_);

		/* potential namespace: cargo */
		std::vector<std::string> backpack_cargo(const object &box_);
		std::vector<std::string> backpack_items(const object &unit_);
		std::vector<std::string> backpack_magazines(const object &unit_);

		/* potential namespace: misc, model, position? */
		sqf::rv_bounding_box bounding_box(const object &model_);
		sqf::rv_bounding_box bounding_box_real(const object &model_);
		vector3 bounding_center(const object &obj_);

		/* potential namespace: controls, ui, gui, misc */
		void button_set_action(int control_id_, const std::string &code_);
		void button_set_action(const control &control_, const std::string &code_);

		/* potential namespace: locations */
		std::string class_name(const location &loc_);
		location create_location(const std::string &classname_, const vector3 &pos_, float size_x_, float size_y_);
		location create_location(const std::string &classname_, vector2 pos_, float size_x_, float size_y_);
		location create_location(const std::string &classname_, const object &obj_, float size_x_, float size_y_);

		/* potential namespace: ai, group, unit */
		std::string combat_mode(const group &loc_);
		std::string combat_mode(const object &loc_);

		/* potential namespace: ai */
		void command_get_out(const object &unit_);
		void command_get_out(std::vector<object> units_);
		void command_stop(const object &unit_);
		void command_stop(std::vector<object> units_);

		/* potential namespace: core, create */
		object create_agent(const std::string &type_, const vector3 &pos_, const std::vector<marker> &markers_ = {}, float placement_ = 0.0f, const std::string &special_ = "NONE");
		object create_mine(const std::string &type_, const vector3 &pos_, const std::vector<marker> &markers_ = {}, float placement_ = 0.0f);
		object create_sound_source(const std::string &type_, const vector3 &pos_, const std::vector<marker> &markers_ = {}, float placement_ = 0.0f);
		object create_trigger(const std::string &type_, const vector3 &pos_, bool make_global_ = true);
		object create_trigger(const std::string &type_, const object &pos_, bool make_global_ = true);

		/* potential namespace: core, create, teams */
		team_member create_team(const std::string &type_, const std::string &name_);

		/* potential namespace: gui, ui */
		void create_gear_dialog(const object &unit_, const std::string &resource_);

		/* potential namespace: misc */
		void create_guarded_point(const side &side_, const vector3 &pos_, float idstatic_, const object &veh_);

		/* potential namespace: vehicle */
		std::vector<object> crew(object _veh);

		/* potential namespace: magazine, items, inventory */
		std::string current_magazine_detail(const object &veh_);

		/* potential namespace: teams */
		std::vector<task> current_tasks(const team_member &team_member_);

		/* potential namespace: gui, ui */
		void cut_obj(const std::string &name_, const std::string &type_, float speed_ = 1.0f);
		void cut_rsc(const std::string &name_, const std::string &type_, float speed_ = 1.0f, bool show_on_map_ = false);
		void cut_text(const std::string &name_, const std::string &type_, float speed_ = 1.0f, bool show_on_map_ = false);
		void enable_debriefing_stats(float left_, float top_, float width_, float height_);

		/* potential namespace: misc */
		void enable_saving(bool enable_);
		void enable_saving(bool enable_, bool autosave_);

		/* potential namespace: rtd, vehicles, afm */
		// TODO std::vector<bool> engines_is_on_rtd(const object &helicopter_);
		// TODO std::vector<float> engines_torque_rtd(const object &helicopter_);
		// TODO std::vector<float> engines_rpm_rtd(const object &helicopter_);

		/* potential namespace: core */
		// TODO std::vector<object> entities(const std::string &type_);

		/* potential namespace: backpack, containers, inventory */
		// TODO std::vector<object> every_backpack(const object &box_);

		/* potential namespace: containers, inventory */
		// TODO std::vector<rv_container> every_container(const object &box_);

		/* potential namespace: ai */
		// TODO rv_destination expected_destination(const object &unit_);

		/* potential namespace: position */
		// TODO vector3 eye_direction(const object &unit_);
		// TODO vector3 eye_pos(const object &unit_);

		/* potential namespace: groups, ai */
		std::string formation(const object &leader_);
		std::string formation(const group &group_);

		std::vector<object> formation_members(const object &unit_);
		vector3 formation_position(const object &unit_);

		/* Potential namespace: core */
		std::vector<rv_crew_member> full_crew(const object &veh_, const std::string &filter_ = "");

		/* potential namespace: misc */
		std::vector<std::string> get_artillery_ammo(const std::vector<object> &units_);

		/* potential namespace: physics, physx, core */
		vector3 get_center_of_mass(const object &obj_);

		/* potential namespace: misc */
		std::vector<float> get_dlcs(float filter_);

		/* potential namespace: dialogs, ui, listbox */
		float lb_add(int control_id_, const std::string &text_);
		float lb_add(const control &control_, const std::string &text_);
		float lb_color(int control_id_, int index_);
		float lb_color(const control &control_, int index_);
		float lb_color_right(int control_id_, int index_);
		float lb_color_right(const control &control_, int index_);
		std::string lb_data(int control_id_, int index_);
		std::string lb_data(const control &control_, int index_);
		void lb_delete(int control_id_, int index_);
		void lb_delete(const control &control_, int index_);
		std::string lb_picture(int control_id_, int index_);
		std::string lb_picture(const control &control_, int index_);
		std::string lb_picture_right(int control_id_, int index_);
		std::string lb_picture_right(const control &control_, int index_);
		// TODO std::vector<float> lb_selection(const control &control_); // USE lb_cur_sel IN A3 https://community.bistudio.com/wiki/lbSelection
		void lb_set_color(int control_id_, int index_, rv_color color_);
		void lb_set_color(const control &control_, int index_, rv_color color_);
		void lb_set_color_right(int control_id_, int index_, rv_color color_);
		void lb_set_color_right(const control &control_, int index_, rv_color color_);
		void lb_set_cur_sel(int control_id_, int index_);
		void lb_set_cur_sel(const control &control_, int index_);
		void lb_set_data(int control_id_, int index_, const std::string &data_);
		void lb_set_data(const control &control_, int index_, const std::string &data_);
		void lb_set_picture(int control_id_, int index_, const std::string &name_);
		void lb_set_picture(const control &control_, int index_, const std::string &name_);
		void lb_set_picture_right(int control_id_, int index_, const std::string &name_);
		void lb_set_picture_right(const control &control_, int index_, const std::string &name_);
		void lb_set_picture_color(int control_id_, int index_, rv_color color_);
		void lb_set_picture_color(const control &control_, int index_, rv_color color_);
		void lb_set_picture_color_disabled(int control_id_, int index_, rv_color color_);
		void lb_set_picture_color_disabled(const control &control_, int index_, rv_color color_);
		void lb_set_picture_color_selected(int control_id_, int index_, rv_color color_);
		void lb_set_picture_color_selected(const control &control_, int index_, rv_color color_);
		void lb_set_tooltip(int control_id_, int index_, const std::string &tooltip_);
		void lb_set_tooltip(const control &control_, int index_, const std::string &tooltip_);
		void lb_set_value(int control_id_, int index_, float val_);
		void lb_set_value(const control &control_, int index_, float val_);
		void lb_sort(const control &control_);
		void lb_sort(const control &control_, const std::string &sort_order_);
		std::string lb_text(int control_id_, int index_);
		std::string lb_text(const control &control_, int index_);
		std::string lb_text_right(int control_id_, int index_);
		std::string lb_text_right(const control &control_, int index_);
		float lb_value(int control_id_, int index_);
		float lb_value(const control &control_, int index_);


		/* 3den */
		std::string current3denoperation();
		object get3dencamera();
		bool get3deniconsvisible();
		bool get3denlinesvisible();
		// TODO array[] get_3den_mouse_over(); //      Array in format: [type,Eden Entity], where type can be: "Object", "Group", "Trigger", "Logic", "Waypoint" or "Marker"
		bool is3den();
		bool is3denmultiplayer();
		float get_3den_action_state(const std::string &value_);
		void edit_3den_mission_attributes(const std::string &value_);
		float add_3den_layer(float value0_, const std::string& value1_);
		bool remove_3den_layer(float value_);
		void remove_all_3den_eventhandlers(const std::string &value_);

		/* Chat */
		namespace __helpers {
			void chat_message(binary_function fnc_, const object &obj_, const std::string &message_);
			vector3 get_pos_loc(unary_function fnc_, const location & loc_);
		}
		void side_chat(const object & obj_, const std::string &message_);
		void global_chat(const object & obj_, const std::string & message_);
		void group_chat(const object & obj_, const std::string & message_);
		void vehicle_chat(const object & obj_, const std::string & message_);
		void command_chat(const object & obj_, const std::string & message_);
		void system_chat(const std::string &message_);
		void custom_chat(const object & obj_, uint32_t channel_id_, const std::string &message_);

		/* Config */
		std::vector<config> config_hierarchy(const config &config_entry_);
        std::string config_name(const config &config_entry_);
        std::vector<config> config_properties(const config &config_entry,const std::string& condition_, bool inherit);
        std::string config_source_mod(const config &config_entry_);
        std::vector<std::string> config_source_mod_list(const config &config_entry_);
        float count(const config &config_entry_);
        //std::vector<game_value> get_array(const config &config_entry_);
        config get_mission_config(const std::string& value_);
        float get_number(const config &config_entry_);
        std::string get_text(const config &config_entry_);
        config inherits_from(const config &config_entry_);
        bool is_array(const config &config_entry_);
        bool is_class(const config &config_entry_);
        bool is_null(const config &config_entry_);
        bool is_number(const config &config_entry_);
        bool is_text(const config &config_entry_);
        std::vector<std::string> config_classes(const std::string& value_, config a_config_);
        void load_overlay(const control &a_control_, config a_config_);
        void new_overlay(const control &a_control_, config a_config_);
        config select(const config &a_config_, float a_number_);
        config campaign_config_file();
        config config_file();
        config config_null();
        config mission_config_file();

		/* Core */
		std::vector<object> all_3den_entities();
		std::vector<object> all_curators();
		std::vector<object> all_dead();
		std::vector<object> all_deadmen();
		std::vector<display> all_displays();
		std::vector<group> all_groups();
		std::vector<marker> all_map_markers();
		std::vector<object> all_mines();
		std::vector<object> all_players();
		// std::vector<site> all_sites(); // This command is depecrated and no longer supported https://community.bistudio.com/wiki/allSites
		std::vector<object> all_units();
		std::vector<object> all_units_uav();

		object create_vehicle(const std::string &type_, const vector3 &pos_);
		object create_vehicle(const std::string &type_, const vector3 &pos_, const std::vector<marker> &markers_, float placement_, const std::string &special_);
		void delete_vehicle(const object &obj_);

		float server_time();
		std::string server_name();

		bool is_null(const object &value_);
		bool is_null(const group &value_);
		bool is_null(const control &value_);
		bool is_null(const display &value_);
		bool is_null(const script &value_);
		bool is_null(const task &value_);

		script script_null();
		task task_null();
		rv_namespace ui_namespace();

		std::vector<script> diag_active_mission_fsms();
		std::vector<script> diag_active_sqf_scripts();
		std::vector<script> diag_active_sqs_scripts();

		bool __sqfassert(bool test_);

        std::vector<control> all_controls(const display &display_);

        std::vector<std::string> all_turrets(const object &vehicle_, bool person_turrets_);

        std::vector<std::string> all_turrets(const object &vehicle_);

        std::vector<std::string> all_variables(const object &value_);
        std::vector<std::string> all_variables(const control &value_);
        std::vector<std::string> all_variables(const team_member &value_);
        std::vector<std::string> all_variables(rv_namespace value_);
        std::vector<std::string> all_variables(const group &value_);
        std::vector<std::string> all_variables(const task &value_);
        std::vector<std::string> all_variables(const location &value_);

		/* Ctrl */
				void ctrl_activate(const control &value_);
		float ctrl_auto_scroll_delay(const control &value_);
		bool ctrl_auto_scroll_rewind(const control &value_);
		float ctrl_auto_scroll_speed(const control &value_);
		bool ctrl_checked(const control &value_);
		std::string ctrl_class_name(const control &value_);
		bool ctrl_committed(const control &value_);
		bool ctrl_delete(const control &value_);
		bool ctrl_enabled(const control &value_);
		bool ctrl_enabled(float value_);
		float ctrl_fade(const control &value_);
		bool ctrl_htmlloaded(const control &value_);
		float ctrl_idc(const control &value_);
		float ctrl_idd(const display &value_);
		void ctrl_map_anim_clear(const control &value_);
		void ctrl_map_anim_commit(const control &value_);
		bool ctrl_map_anim_done(const control &value_);
		float ctrl_map_scale(const control &value_);
		std::string ctrl_model(const control &value_);
		float ctrl_model_scale(const control &value_);
		display ctrl_parent(const control &value_);
		control ctrl_parent_controls_group(const control &value_);
		float ctrl_scale(const control &value_);
		void ctrl_set_focus(const control &value_);
		bool ctrl_shown(const control &value_);
		std::string ctrl_text(const control &value_);
		std::string ctrl_text(float value_);
		float ctrl_text_height(const control &value_);
		std::string ctrl_text_secondary(const control &value_);
		float ctrl_type(const control &value_);
		bool ctrl_visible(float value_);

		void ctrl_commit(const control &value0_, float value1_);
        void ctrl_enable(int control_id_, bool enable_);
        void ctrl_enable(const control &control_, bool enable_);
		void ctrl_remove_all_event_handlers(const control &value0_, const std::string& value1_);
		void ctrl_set_auto_scroll_delay(const control &value0_, float value1_);
		void ctrl_set_auto_scroll_rewind(const control &value0_, bool value1_);
		void ctrl_set_auto_scroll_speed(const control &value0_, float value1_);
		void ctrl_set_checked(const control &value0_, bool value1_);
		void ctrl_set_fade(const control &value0_, float value1_);
		void ctrl_set_font(const control &value0_, const std::string& value1_);
		void ctrl_set_font_h1(const control &value0_, const std::string& value1_);
		void ctrl_set_font_h1b(const control &value0_, const std::string& value1_);
		void ctrl_set_font_h2(const control &value0_, const std::string& value1_);
		void ctrl_set_font_h2b(const control &value0_, const std::string& value1_);
		void ctrl_set_font_h3(const control &value0_, const std::string& value1_);
		void ctrl_set_font_h3b(const control &value0_, const std::string& value1_);
		void ctrl_set_font_h4(const control &value0_, const std::string& value1_);
		void ctrl_set_font_h4b(const control &value0_, const std::string& value1_);
		void ctrl_set_font_h5(const control &value0_, const std::string& value1_);
		void ctrl_set_font_h5b(const control &value0_, const std::string& value1_);
		void ctrl_set_font_h6(const control &value0_, const std::string& value1_);
		void ctrl_set_font_h6b(const control &value0_, const std::string& value1_);
		void ctrl_set_font_height(const control &value0_, float value1_);
		void ctrl_set_font_height_h1(const control &value0_, float value1_);
		void ctrl_set_font_height_h2(const control &value0_, float value1_);
		void ctrl_set_font_height_h3(const control &value0_, float value1_);
		void ctrl_set_font_height_h4(const control &value0_, float value1_);
		void ctrl_set_font_height_h5(const control &value0_, float value1_);
		void ctrl_set_font_height_h6(const control &value0_, float value1_);
		void ctrl_set_font_height_secondary(const control &value0_, float value1_);
		void ctrl_set_font_p(const control &value0_, const std::string& value1_);
		void ctrl_set_font_p(const control &value0_, float value1_);
		void ctrl_set_font_pb(const control &value0_, const std::string& value1_);
		void ctrl_set_font_secondary(const control &value0_, const std::string& value1_);
		void ctrl_set_model(const control &value0_, const std::string& value1_);
		void ctrl_set_model_scale(const control &value0_, float value1_);
		void ctrl_set_scale(const control &value0_, float value1_);
		void ctrl_set_structured_text(const control &value0_, const std::string& value1_);
		void ctrl_set_text(const control &value0_, const std::string& value1_);
        void ctrl_set_text(int control_id_, const std::string &text_);
		void ctrl_set_text_secondary(const control &value0_, const std::string& value1_);
		void ctrl_set_tooltip(const control &value0_, const std::string& value1_);
		void ctrl_show(const control &value0_, bool value1_);
        void ctrl_show(int control_id_, bool show_);

		/* Curator */
		object curatorcamera();
		object curatormouseover();
		std::vector<object> curatorselected();
		void opencuratorinterface();
		bool shown_curatorcompass();
		float curator_camera_area_ceiling(const object &value_);
		bool curator_editing_area_type(const object &value_);
		float curator_points(const object &value_);
		float curator_waypoint_cost(const object &value_);
		object get_assigned_curator_logic(const object &value_);
		object get_assigned_curator_unit(const object &value_);
		void remove_all_curator_addons(const object &value_);
		void remove_all_curator_camera_areas(const object &value_);
		void remove_all_curator_editing_areas(const object &value_);
		void show_curator_compass(bool value_);
		void unassign_curator(const object &value_);
		void add_curator_points(const object &value0_, float value1_);
		void allow_curator_logic_ignore_areas(const object &value0_, bool value1_);
		float curator_coef(const object &value0_, const std::string &value1_);
		void remove_curator_camera_area(const object &value0_, float value1_);
		void remove_curator_editing_area(const object &value0_, float value1_);
		void set_curator_camera_area_ceiling(const object &value0_, float value1_);
		void set_curator_editing_area_type(const object &value0_, bool value1_);
		void set_curator_waypoint_cost(const object &value0_, float value1_);

		std::vector<std::string> curator_addons(const object &curator_module_);
		std::vector<object> curator_editable_objects(const object &curator_module_);

		/* Group */
		bool group_icon_selectable();
		// TODO std::array<bool, 2> group_icons_visible();
		group grp_null();
		void clear_group_icons(const group &value_);
		group create_group(const side &value_);
		void delete_group(const group &value_);

		group group_from_net_id(const std::string &value_);
		std::string group_id(const group &value_);
		float group_owner(const group &value_);
		bool set_group_owner(const group &value0_, float value1_);

		object leader(const group &value_);
		void group_radio(const object &value0_, const std::string& value1_);
		void remove_group_icon(const group &value0_, float value1_);
		void select_leader(const object &value0_, const group &value1_);
		float current_waypoint(const group &value_);
		void set_group_icons_selectable(bool value_);

		/* Marker */
		void delete_marker(const std::string& value_);
		void delete_marker_local(const std::string& value_);
		float marker_alpha(const std::string& value_);
		float marker_dir(const std::string& value_);

		std::string marker_brush(const std::string& value_);
		std::string marker_color(const std::string& value_);
		std::string marker_shape(const std::string& value_);
		std::string marker_text(const std::string& value_);
		std::string marker_type(const std::string& value_);

		void set_marker_alpha(float value0_, const std::string& value1_);
		void set_marker_alpha_local(float value0_, const std::string& value1_);
		void set_marker_dir(float value0_, const std::string& value1_);
		void set_marker_dir_local(float value0_, const std::string& value1_);

		std::string get_marker_color(const std::string& value_);
		std::string get_marker_type(const std::string& value_);
		vector3 get_marker_pos(const std::string& value_);
		vector2 get_marker_size(const std::string& value_);

        std::string create_marker(const std::string &name_, const vector3 &pos_);
        std::string create_marker(const std::string &name_, const vector2 &pos_);
        std::string create_marker(const std::string &name_, const object &pos_);
        std::string create_marker_local(const std::string &name_, const vector3 &pos_);
        std::string create_marker_local(const std::string &name_, const vector2 &pos_);
        std::string create_marker_local(const std::string &name_, const object &pos_);

		/* Multiplayer */
		bool local(const object &value_);
		bool local(const group &value_);
		bool is_server();
		bool is_multiplayer();
		bool is_dedicated();
		bool did_jip();

		/* Position */
		namespace __helpers {
			vector3 get_pos_obj(unary_function fnc_, const object & obj_);
		}

		vector3 get_pos(const object & obj_);
		vector3 get_pos(const location & loc_);
		vector3 get_pos_asl(const object & obj_);
		vector3 get_pos_atl(const object & obj_);
		vector3 get_pos_aslw(const object & obj_);
		vector3 visible_position(const object & obj_);
		vector3 visible_position_asl(const object & obj_);
		vector3 position(const object & obj_);
		vector3 get_pos_visual(const object & obj_);
		vector3 get_pos_asl_visual(const object & obj_);
		vector3 get_pos_atl_visual(const object & obj_);
		vector3 aim_pos(const object & obj_);

		void set_pos(const object & obj_, const vector3 &pos_);
		void set_pos_asl(const object & obj_, const vector3 & pos_);
		void set_pos_asl2(const object & obj_, const vector3 & pos_);
		void set_pos_aslw(const object & obj_, const vector3 & pos_);
		void set_pos_atl(const object & obj_, const vector3 & pos_);

		/////////////////////////////////////* Coordinate converters */
		vector3 agl_to_asl(const vector3 & agl_);
		vector3 asl_to_agl(const vector3 & asl_);
		vector3 atl_to_asl(const vector3 & atl_);
		vector3 asl_to_atl(const vector3 & asl_);

		/* Waypoint */
		struct waypoint
        {
            group wgroup;
            float windex;

            waypoint(const group& rv_game_value, uint32_t windex)
                : wgroup(rv_game_value),
                windex((float)windex)
            {
            }

            waypoint(const game_value& rv_game_value)
                : wgroup(group(rv_game_value[0].rv_data)),
                windex(rv_game_value[1])
            {
            }

            std::vector<game_value> __to_gv_vec()
            {
                return std::vector<game_value>{wgroup, game_value(windex)};
            }

            game_value __to_gv()
            {
                return game_value(std::vector<game_value>{ wgroup, windex });
            }

            static const std::string __speed_lookup[4];
            enum class speed
            {
                UNCHANGED = 0,
                LIMITED = 1,
                NORMAL = 2,
                FULL = 3
            };
            static const std::string __show_lookup[4];
            enum class show
            {
                NEVER,
                EASY,
                ALWAYS,
                WAYPOINT_ERROR
            };
            static const std::string __type_lookup[22];
            enum class type
            {
                MOVE,
                DESTROY,
                GETIN,
                SAD,
                JOIN,
                LEADER,
                GETOUT,
                CYCLE,
                LOAD,
                UNLOAD,
                TR_UNLOAD,
                HOLD,
                SENTRY,
                GUARD,
                TALK,
                SCRIPTED,
                SUPPORT,
                GETIN_NEAREST,
                DISMISS,
                LOITER,
                AND,
                OR
            };
            static const std::string __behaviour_lookup[6];
            enum class behaviour
            {
                UNCHANGED,
                CARELESS,
                SAFE,
                AWARE,
                COMBAT,
                STEALTH
            };
            static const std::string __combat_mode_lookup[6];
            enum class combat_mode
            {
                NO_CHANGE,
                BLUE,
                GREEN,
                WHITE,
                YELLOW,
                RED

            };
            static const std::string __formation_lookup[10];
            enum class formation
            {
                NO_CHANGE,
                COLUMN,
                STAG_COLUMN,
                WEDGE,
                ECH_LEFT,
                ECH_RIGHT,
                VEE,
                LINE,
                FILE,
                DIAMOND
            };
            static const std::string __loiter_lookup[2];
            enum class loiter_type
            {
                CIRCLE,
                CIRCLE_L
            };


            static speed __parse_speed(const std::string& subject_)
            {
                for (size_t i = 0; i < __speed_lookup->length(); i++)
                {
                    if (subject_ == __speed_lookup[i])
                    {
                        return static_cast<speed>(i);
                    }
                }
                throw 712;
            }
            static show __parse_show(const std::string& subject_)
            {
                for (size_t i = 0; i < __show_lookup->length(); i++)
                {
                    if (subject_ == __show_lookup[i])
                    {
                        return static_cast<show>(i);
                    }
                }
                throw 712;
            }
            static type __parse_type(const std::string& subject_)
            {
                for (size_t i = 0; i < __type_lookup->length(); i++)
                {
                    if (subject_ == __type_lookup[i])
                    {
                        return static_cast<type>(i);
                    }
                }
                throw 712;
            }
            static behaviour __parse_behaviour(const std::string& subject_)
            {
                for (size_t i = 0; i < __behaviour_lookup->length(); i++)
                {
                    if (subject_ == __behaviour_lookup[i])
                    {
                        return static_cast<behaviour>(i);
                    }
                }
                throw 712;
            }
            static combat_mode __parse_combat_mode(const std::string& subject_)
            {
                for (size_t i = 0; i < __combat_mode_lookup->length(); i++)
                {
                    if (subject_ == __combat_mode_lookup[i])
                    {
                        return static_cast<combat_mode>(i);
                    }
                }
                throw 712;
            }
            static formation __parse_formation(const std::string& subject_)
            {
                for (size_t i = 0; i < __formation_lookup->length(); i++)
                {
                    if (subject_ == __formation_lookup[i])
                    {
                        return static_cast<formation>(i);
                    }
                }
                throw 712;
            }
            static loiter_type __parse_loiter_type(const std::string& subject_)
            {
                for (size_t i = 0; i < __loiter_lookup->length(); i++)
                {
                    if (subject_ == __loiter_lookup[i])
                    {
                        return static_cast<loiter_type>(i);
                    }
                }
                throw 712;
            }

            static std::string __get_enum_as_str(speed subject_)
            {
                return __speed_lookup[(int)subject_];
            }
            static std::string __get_enum_as_str(show subject_)
            {
                return __show_lookup[(int)subject_];
            }
            static std::string __get_enum_as_str(type subject_)
            {
                return __type_lookup[(int)subject_];
            }
            static std::string __get_enum_as_str(behaviour subject_)
            {
                return __behaviour_lookup[(int)subject_];
            }
            static std::string __get_enum_as_str(combat_mode subject_)
            {
                return __combat_mode_lookup[(int)subject_];
            }
            static std::string __get_enum_as_str(formation subject_)
            {
                return __formation_lookup[(int)subject_];
            }
            static std::string __get_enum_as_str(loiter_type subject_)
            {
                return __loiter_lookup[(int)subject_];
            }

        };
        // It's ficking replaced at compile time anyway, why is this nessecary.................
        /*

        */
        /*!
        @brief Adds (or inserts when index is given) a new waypoint to a group.

        The waypoint is placed randomly within a circle with the given center and radius. The function returns the placed waypoint.

        @param gp_ The group to add the waypoint to.
        @param center_ The poition of the center of the waypoint placement radius.
        @param radius_ The radius of the waypoint placement area.
        @param index_ [OPTIONAL] The index of the waypoint to insert this waypoint after.
        @param name_ [OPTIONAL] The waypoint name

        @return Returns the placed waypoint.

        @sa https://community.bistudio.com/wiki/addWaypoint
        */
        waypoint add_waypoint(group & gp_, const vector3 & center_, float radius_, int index_ = -1, const std::string & name_ = "");

        /*!
        @brief Adds (or inserts when index is given) a new waypoint to a group.

        The waypoint is placed randomly within a circle with the given center and radius. The function returns the placed waypoint.

        @param gp_ The group to add the waypoint to.
        @param center_ An object to be the center of the waypoint placement radius.
        @param radius_ The radius of the waypoint placement area.
        @param index_ [OPTIONAL] The index of the waypoint to insert this waypoint after.
        @param name_ [OPTIONAL] The waypoint name

        @return Returns the placed waypoint.

        @sa 		https://community.bistudio.com/wiki/addWaypoint
        */
        waypoint add_waypoint(group & gp_, const object & center_, float radius_, int index_ = -1, const std::string & name_ = "");

        /*!
        @brief  Removes the specified waypoint.

        @param  wp_ Waypoint to delete

        @sa https://community.bistudio.com/wiki/deleteWaypoint
        */
        void delete_waypoint(waypoint & wp_);


        void copy_waypoints(group & to_, group & from_);

        /************************************************  GETTERS   ************************************************/

        /*!
        @brief Gets the object attached to the waypoint.

        @param wp_ Waypoint to use

        @return Object attached to the waypoint, if any.
        */
        object waypoint_attached_object(waypoint& wp_);

        /*!
        @brief Gets the vehicle attached to the waypoint.

        @param wp_ Waypoint to use

        @return Vehicle attached to the waypoint, if any.

        @sa https://community.bistudio.com/wiki/waypointAttachedVehicle
        */
        object waypoint_attached_vehicle(waypoint & wp_);

        /*!
        @brief Gets the waypoint behavior.

        @param wp_ Waypoint to use

        @return Returns the behaviour of the waypoint.

        @sa waypoint::behaviour
        */
        waypoint::behaviour waypoint_behaviour(waypoint & wp_);

        /*!
        @brief Gets the waypoint combat mode.

        @param wp_ Waypoint to use

        @return Returns the combat mode of the waypoint.

        @sa waypoint::combat_mode
        @sa https://community.bistudio.com/wiki/2D_Editor:_Waypoints#Combat_Mode
        */
        waypoint::combat_mode waypoint_combat_mode(waypoint & wp_);

        /*!
        @brief Gets the radius around the waypoint where the waypoint is completed.

        @param wp_ Waypoint to use

        @return Returns the completeion radius of the waypoint.

        @sa https://community.bistudio.com/wiki/waypointCompletionRadius
        */
        float waypoint_completeion_radius(waypoint & wp_);

        /*!
        @brief Gets the waypoint description.

        @param wp_ Waypoint to use

        @return Returns the waypoint description

        @sa https://community.bistudio.com/wiki/waypointDescription
        */
        std::string waypoint_description(waypoint & wp_);

        /*!
        @brief Gets the waypoint description.

        @param wp_ Waypoint to use

        @return Returns the waypoint formation, enumeratred.

        @sa https://community.bistudio.com/wiki/waypointFormation
        */
        waypoint::formation waypoint_formation(waypoint & wp_);

        /*!
        @brief Gets the house position assigned to the waypoint.

        @param wp_ Waypoint to use

        @return Returns the house position.

        @sa https://community.bistudio.com/wiki/waypointHousePosition
        */
        float waypoint_house_position(waypoint & wp_);

        /*!
        @brief Gets the waypoint loiter radius.

        @param wp_ Waypoint to use

        @return Returns the loiter radius.

        @sa https://community.bistudio.com/wiki/waypointLoiterRadius
        */
        float waypoint_loiter_radius(waypoint & wp_);

        /*!
        @brief Gets the waypoint loiter type.

        @param wp_ Waypoint to use

        @return Returns the loiter type, enumerated.

        @sa https://community.bistudio.com/wiki/waypointLoiterType
        */
        waypoint::loiter_type waypoint_loiter_type(waypoint & wp_);

        /*!
        @brief Gets the waypoint name.

        @param wp_ Waypoint to use

        @return The name assigned to the waypoint.

        @sa https://community.bistudio.com/wiki/waypointName
        */
        std::string waypoint_name(waypoint & wp_);

        /*!
        @brief Get Waypoint's Position.

        @param wp_ Waypoint to use

        @return The position of the waypoint.

        @sa https://community.bistudio.com/wiki/waypointPosition
        */
        vector3 waypoint_position(waypoint & wp_);

        /*!
        @brief  	Returns an array of waypoints for the specified unit/group

        @param  	gp_ Group to retrieve waypoints of.

        @return The position of the waypoint.

        @sa https://community.bistudio.com/wiki/waypoints
        */
        std::vector<waypoint> waypoints(group & gp_);

        /*!
        @brief Gets the waypoint script.

        @param wp_ Waypoint to use

        @return The position of the waypoint.

        @sa https://community.bistudio.com/wiki/waypointScript
        */
        std::string waypoint_script(waypoint & wp_);

        /*!
        @brief Gets the waypoint show/hide status.

        @param wp_ Waypoint to use

        @return Gets the showhide status, enumerated.

        @sa https://community.bistudio.com/wiki/waypointShow
        */
        waypoint::show waypoint_show(waypoint & wp_);

        /*!
        @brief Gets the waypoint movement speed.

        @param wp_ Waypoint to use

        @return Gets the waypoint speed, enumerated.

        @sa https://community.bistudio.com/wiki/waypointSpeed
        */
        waypoint::speed waypoint_speed(waypoint & wp_);
        // TODO waypoint_statements needs struct for return value
        // TODO waypoint_timeout needs struct for return value

        /*!
        @brief Gets the waypoint type.

        @param wp_ Waypoint to use

        @return The waypoint type, enumerated.

        @sa https://community.bistudio.com/wiki/waypointType
        */
        waypoint::type waypoint_type(waypoint & wp_);

        /*!
        @brief Returns the visibility of the waypoint.

        @param wp_ Waypoint to use

        @return The waypoint visibility.

        @sa https://community.bistudio.com/wiki/waypointVisible
        */
        bool waypoint_visible(waypoint & wp_);
        bool waypoint_exists(waypoint & wp_); // NOTE Not SQF command.

        std::vector<waypoint> synchronized_waypoints(waypoint & wp_);
        std::vector<waypoint> synchronized_waypoints(object & obj_);

        void set_current_waypoint(group & gp_, waypoint & wp_);
        void set_waypoint_behaviour(waypoint & wp_, waypoint::behaviour mode_);
        void set_waypoint_combat_mode(waypoint & wp_, waypoint::combat_mode mode_);
        void set_waypoint_completion_radius(waypoint & wp_, float radius_);
        void set_waypoint_description(waypoint & wp_, std::string text_);
        void set_waypoint_formation(waypoint & wp_, waypoint::formation formation_);
        void set_waypoint_house_position(waypoint & wp_, float house_pos_);
        void set_waypoint_loiter_radius(waypoint & wp_, float radius_);
        void set_waypoint_loiter_type(waypoint & wp_, waypoint::loiter_type type_);
        void set_waypoint_name(waypoint & wp_, std::string name_);
        void set_waypoint_position(waypoint & wp_, vector3 & pos_, float radius_);
        void set_waypoint_script(waypoint & wp_, std::string command_);
        void set_waypoint_speed(waypoint& wp_, waypoint::speed mode_);
        void set_waypoint_statements(waypoint& wp_, std::string condition_, std::string statement_);
        void set_waypoint_timeout(waypoint& wp_, float min_, float mid_, float max_);
        void set_waypoint_type(waypoint& wp_, waypoint::type type_);
        void set_waypoint_visible(waypoint& wp_, bool visibility_);

        void show_waypoint(waypoint& wp_, std::string show_);

        void synchronize_waypoint(waypoint& wp_, std::vector<waypoint> others_);
        void synchronize_waypoint(object& trigger_, std::vector<waypoint> others_);

        void waypoint_attach_object(waypoint& wp_, int obj_id_);
        void waypoint_attach_object(waypoint& wp_, object obj_);

        float current_waypoint(group gp_);
        bool waypoints_enabled_uav(object value_);
        void enable_uavwaypoints(bool value0_, object value1_);

		/* World */

        struct game_date
        {
            float year;
            float month;
            float day;
            float hour;
            float minute;

            game_date(float year_, float month_, float day_, float hour_, float minute_)
            {
                year = year_;
                month = month_;
                day = day_;
                hour = hour_;
                minute = minute_;
            }

            static game_date from_vector(const std::vector<float> &date_vector_)
            {
                return game_date(date_vector_[0], date_vector_[1], date_vector_[2], date_vector_[3], date_vector_[4]);
            }

            std::vector<float> to_vector() const
            {
                std::vector<float> ret_val{ year, month, day, hour, minute };
                return ret_val;
            }
        };

        float world_size();
        std::string world_name();
        float wind_str();
        float wind_dir();

        vector3 wind();
        float waves();
        // TODO void set_waves(float lerp_time_, float val_); // TODO

        float time();
		// TODO game_date date();

        float time_multiplier();

        float date_to_number(game_date date_);

		float acc_time();
		object agent(const team_member &value_);
		std::vector<std::string> activated_addons();
		std::vector<team_member> agents();
		//std::vector<?> airdensity_curvertd(); // no entry on the biki

		float armorypoints();
		float benchmark();
		side blufor();
		std::string briefingname();
		bool cadetmode();
		object cameraon();
		std::string cameraview();
		config campaignconfigfile();
		bool cheatsenabled();
		side civilian();
		void clearforcesrtd();
		void clearitempool();
		void clearmagazinepool();
		void clearradio();
		void clearweaponpool();
		float clientowner();
		std::string commandingmenu();
		config configfile();
		config confignull();
		control controlnull();
		std::string copyfromclipboard();
		float currentchannel();
		rv_namespace currentnamespace();
		object cursortarget();
		float daytime();
		float diag_fps();
		float diag_fpsmin();
		float diag_frameno();
		float diag_ticktime();
		bool dialog();
		float difficulty();
		bool difficulty_enabled_rtd();
		void disable_debriefing_stats();
		void disable_serialization();
		display display_null();
		float distribution_region();
		side east();
		void enable_end_dialog();
		void end_loading_screen();
		float estimated_end_server_time();
		void exit();
		void finish_mission_init();
		bool fog();
		float fog_forecast();
		// TODO std::vector<float> fog_params();
		void force_end();
		void force_weather_change();
		bool free_look();
		// TODO array[] getartillerycomputersettings(); // ["Semi (medium)","HE Mortar Shells",0]
		std::string getclientstate();
		// TODO not on biki getdlcassetsusage();
		float getelevationoffset();
		// TODO not on biki std::vector<std::string> getmissiondlcs();
		// TODO vector2 get_mouse_position();
		// TODO std::array<float, 2> get_object_view_distance();
		bool get_remote_sensors_disabled();
		// TODO game_resolution get_resolution();
		float get_shadow_distance();
		float get_total_dlc_usage_time();
		float gusts();
		void halt();
		bool has_interface();
		bool hc_shown_bar();
		// TODO hud_movement_levels hudmovementlevels();
		float humidity();
		side independent();
		void init_ambient_life();
		bool is_autotest();
		bool is_filepatching_enabled();
		bool is_instructor_figure_enabled();
		bool is_pip_enabled();
		bool is_steam_mission();
		bool is_stream_friendly_ui_enabled();
		bool is_stress_damage_enabled();
		bool is_tut_hints_enabled();
		std::string language();
		// TODO std::vector<std::array<std::string, 2>> library_credits(); //USE A PAIR FOR FUCK SAKE!
		std::vector<std::string> library_disclaimers();
		float lightnings();
		std::string line_break();
		void load_game();
		location location_null();
		void log_entities();
		void map_anim_clear();
		void map_anim_commit();
		bool map_anim_done();
		bool mark_as_finished_on_steam();
		float mission_difficulty();
		std::string mission_name();
		rv_namespace mission_namespace();
		float moon_intensity();
		float music_volume();
		float next_weather_change();
		object obj_null();
		side opfor();
		float overcast();
		float overcast_forecast();
		rv_namespace parsing_namespace();
		float particles_quality();
		float pi();
		float pixel_h();
		float pixel_w();
		std::vector<object> playable_units();
		object player();
		float player_respawn_time();
		side player_side();
		// TODO implement product_version productversion();
		std::string profile_name();
		rv_namespace profile_namespace();
		std::string profile_namesteam();
		float rain();
		float rainbow();
		void reset_cam_shake();
		side resistance();
		bool reversed_mouse_y();
		void run_init_script();

		bool visible_watch();
		bool visible_map();
		bool visible_gps();
		bool visible_compass();
		float view_distance();
		bool team_switch_enabled();
		void team_switch();

		float system_of_units();
		float sun_or_moon(); // BUT WHICH ONE IS IT!?!?!??!!?
		float sound_volume();
		bool sling_load_assistant_shown();
		void simul_weather_sync();
		void select_no_player();
		bool saving_enabled();
		void save_profile_namespace();

		std::vector<object> switchable_units();

		float safe_zone_x();
		float safe_zone_y();
		float safe_zone_h();
		float safe_zone_w();
		float safe_zone_x_abs();
		float safe_zone_w_abs();

		bool shown_artillerycomputer();
		bool shown_chat();
		bool shown_compass();
		bool shown_gps();
		bool shown_hud();
		bool shown_map();
		bool shown_pad();
		bool shown_radio();
		bool shown_uavfeed();
		bool shown_warrant();
		bool shown_watch();

		std::string action_name(const std::string &value_);
		void activate_key(const std::string &value_);
		void add_switchable_unit(const object &value_);
		float air_density_rtd(float value_);
		void airport_side(float value_);
		bool alive(const object &value_);
		std::string animation_state(const object &value_);
		object assigned_commander(const object &value_);
		object assigned_driver(const object &value_);
		object assigned_gunner(const object &value_);
		object assigned_target(const object &value_);
		std::string assigned_team(const object &value_);
		object assigned_vehicle(const object &value_);

		std::string backpack(const object &value_);
		object backpack_container(const object &value_);
		std::string behaviour(const object &value_);
		std::string binocular(const object &value_);
		void break_out(const std::string &value_);
		void break_to(const std::string &value_);
		void buldozer(bool value_);
		bool buldozer(const std::string &value_);
		std::string button_action(const control &value_);
		std::string button_action(float value_);
		bool cam_committed(const object &value_);
		void cam_destroy(const object &value_);
		bool cam_preloaded(const object &value_);
		object cam_target(const object &value_);
		void cam_use_nvg(bool value_);
		void camera_effect_enable_hud(bool value_);
		float camera_interest(const object &value_);
		bool can_fire(const object &value_);
		bool can_move(const object &value_);
		bool can_stand(const object &value_);
		bool can_unload_in_combat(const object &value_);
		bool captive(const object &value_);
		float captive_num(const object &value_);
		bool cb_checked(const control &value_);
		bool channel_enabled(float value_);
		bool check_aifeature(const std::string &value_);
		void clear_all_items_from_backpack(const object &value_);
		void clear_backpack_cargo(const object &value_);
		void clear_backpack_cargo_global(const object &value_);
		void clear_item_cargo(const object &value_);
		void clear_item_cargo_global(const object &value_);
		void clear_magazine_cargo(const object &value_);
		void clear_magazine_cargo_global(const object &value_);
		void clear_overlay(const control &value_);
		void clear_weapon_cargo(const object &value_);
		void clear_weapon_cargo_global(const object &value_);
		void close_dialog(float value_);
		void close_overlay(const control &value_);
		void collapse_object_tree(const control &value_);
		float collective_rtd(const object &value_);
		object commander(const object &value_);
		void comment(const std::string &value_);
		void commit_overlay(const control &value_);
		bool completed_fsm(float value_);
		void copy_to_clipboard(const std::string &value_);
		float count(const std::string &value_);
		side create_center(const side &value_);
		bool create_dialog(const std::string &value_);
		void create_vehicle_crew(const object &value_);
		std::string current_command(const object &value_);
		std::string current_magazine(const object &value_);
		std::string current_muzzle(const object &value_);
		float current_vision_mode(const object &value_);
		std::string current_weapon(const object &value_);
		std::string current_weapon_mode(const object &value_);
		float current_zeroing(const object &value_);
		float damage(const object &value_);
		void de_activate_key(const std::string &value_);
		float debriefing_text(const std::string &value_);
		void delete_center(const side &value_);
		void delete_collection(const object &value_);
		bool delete_identity(const std::string &value_);

		void delete_site(const object &value_);
		bool delete_status(const std::string &value_);
		void detach(const object &value_);
		bool did_jipowner(const object &value_);
		bool difficulty_enabled(const std::string &value_);
		float direction(const object &value_);
		void disable_remote_sensors(bool value_);
		void disable_user_input(bool value_);
		void dissolve_team(const std::string &value_);
		object driver(const object &value_);
		void echo(const std::string &value_);
		// TODO void edit(const std::string &value_); // Are we sure this is a valid sqf script command?
		object effective_commander(const object &value_);
		void enable_cam_shake(bool value_);
		void enable_caustics(bool value_);
		void enable_diag_legend(bool value_);
		void enable_engine_artillery(bool value_);
		void enable_environment(bool value_);
		void enable_radio(bool value_);
		void enable_sat_normal_on_detail(bool value_);
		void enable_sentences(bool value_);
		void enable_stress_damage(bool value_);
		void enable_team_switch(bool value_);
		void enable_traffic(bool value_);
		void end_mission(const std::string &value_);
		void estimated_time_left(float value_);
		float exec_fsm(const std::string &value_);
		void export_jipmessages(const std::string &value_);
		std::string face(const object &value_);
		std::string faction(const object &value_);
		void fail_mission(const std::string &value_);
		void fill_weapons_from_pool(const object &value_);
		display find_display(float value_);
		bool finite(float value_);
		object first_backpack(const object &value_);
		object flag(const object &value_);
		object flag_owner(const object &value_);
		side flag_side(const object &value_);
		std::string flag_texture(const object &value_);
		bool fleeing(const object &value_);
		void force_map(bool value_);
		void force_respawn(const object &value_);
		object form_leader(const object &value_);
		float formation_direction(const object &value_);
		object formation_leader(const object &value_);
		std::string formation_task(const object &value_);
		float fuel(const object &value_);
		float gear_idcammo_count(float value_);
		float gear_slot_ammo_count(const control &value_);
		std::string gear_slot_data(const control &value_);
		float get_aiming_coef(const object &value_);
		float get_ammo_cargo(const object &value_);
		float get_anim_aim_precision(const object &value_);
		float get_anim_speed_coef(const object &value_);
		float get_bleeding_remaining(const object &value_);
		float get_burning_value(const object &value_);
		object get_connected_uav(const object &value_);
		float get_custom_aim_coef(const object &value_);
		float get_dlcusage_time(float value_);
		float get_dammage(const object &value_);
		float get_dir(const object &value_);
		float get_dir_visual(const object &value_);
		object get_editor_camera(const control &value_);
		std::string get_editor_mode(const control &value_);
		float get_fatigue(const object &value_);
		float get_fuel_cargo(const object &value_);

		float get_mass(const object &value_);
		float get_object_dlc(const object &value_);
		float get_object_type(const object &value_);
		float get_oxygen_remaining(const object &value_);
		float get_player_channel(const object &value_);
		std::string get_player_uid(const object &value_);
		float get_repair_cargo(const object &value_);
		float get_rotor_brake_rtd(const object &value_);
		object get_sling_load(const object &value_);
		float get_stamina(const object &value_);
		float get_stat_value(const std::string &value_);
		float get_suppression(const object &value_);
		float get_weapon_sway(const object &value_);
		float get_wings_orientation_rtd(const object &value_);
		float get_wings_position_rtd(const object &value_);
		std::string goggles(const object &value_);

		object gunner(const object &value_);
		std::string handgun_magazine(const object &value_);
		std::string handgun_weapon(const object &value_);
		float hands_hit(const object &value_);
		object hc_leader(const group &value_);
		void hc_remove_all_groups(const object &value_);
		void hc_show_bar(bool value_);
		std::string headgear(const object &value_);
		void hide_body(const object &value_);
		void hide_object(const object &value_);
		void hide_object_global(const object &value_);
		void hint_c(const std::string &value_);
		std::string hmd(const object &value_);
		std::string image(const std::string &value_);
		void import_all_groups(const control &value_);
		std::string incapacitated_state(const object &value_);
		bool inflamed(const object &value_);
		float input_action(const std::string &value_);
		bool is_able_to_breathe(const object &value_);
		bool is_aim_precision_enabled(const object &value_);
		bool is_auto_hover_on(const object &value_);
		bool is_auto_trim_on_rtd(const object &value_);
		bool is_autonomous(const object &value_);
		bool is_bleeding(const object &value_);
		bool is_burning(const object &value_);
		bool is_collision_light_on(const object &value_);
		bool is_copilot_enabled(const object &value_);
		bool is_dlcavailable(float value_);
		bool is_engine_on(const object &value_);
		bool is_forced_walk(const object &value_);
		bool is_formation_leader(const object &value_);
		bool is_hidden(const object &value_);
		bool is_in_remains_collector(const object &value_);
		bool is_key_active(const std::string &value_);
		bool is_light_on(const object &value_);
		bool is_localized(const std::string &value_);
		bool is_manual_fire(const object &value_);
		bool is_marked_for_collection(const object &value_);

		bool is_object_hidden(const object &value_);
		bool is_object_rtd(const object &value_);
		bool is_player(const object &value_);
		bool is_real_time(const control &value_);
		bool is_showing(const control &value_);
		bool is_sprint_allowed(const object &value_);
		bool is_stamina_enabled(const object &value_);
		bool is_touching_ground(const object &value_);
		bool is_turned_out(const object &value_);
		bool is_uavconnected(const object &value_);
		bool is_walking(const object &value_);
		bool is_weapon_deployed(const object &value_);
		bool is_weapon_rested(const object &value_);
		std::string key_image(float value_);
		std::string key_name(float value_);
		std::string land_result(const object &value_);
		object laser_target(const object &value_);
		void lb_clear(const control &value_);
		void lb_clear(float value_);
		float lb_cur_sel(const control &value_);
		float lb_cur_sel(float value_);
		float lb_size(const control &value_);
		float lb_size(float value_);
		float lb_sort_by_value(const control &value_);
		object leader(const object &value_);
		bool leaderboard_de_init(const std::string &value_);
		bool leaderboard_init(const std::string &value_);
		bool leaderboard_request_rows_friends(const std::string &value_);
		float leaderboard_state(const std::string &value_);
		std::string life_state(const object &value_);
		void light_detach_object(const object &value_);
		std::string light_is_on(const object &value_);
		void lnb_clear(const control &value_);
		void lnb_clear(float value_);
		float lnb_cur_sel_row(const control &value_);
		float lnb_cur_sel_row(float value_);
		float load(const object &value_);
		float load_abs(const object &value_);
		float load_backpack(const object &value_);
		std::string load_file(const std::string &value_);
		float load_uniform(const object &value_);
		float load_vest(const object &value_);
		std::string localize(const std::string &value_);
		bool lock_identity(const object &value_);
		float locked(const object &value_);
		bool locked_driver(const object &value_);
		bool mine_active(const object &value_);
		float morale(const object &value_);
		void move_out(const object &value_);
		float move_time(const object &value_);
		bool move_to_completed(const object &value_);
		bool move_to_failed(const object &value_);
		std::string name(const object &value_);
		std::string name_sound(const object &value_);
		object nearest_building(const object &value_);
		float need_reload(const object &value_);
		std::string net_id(const object &value_);
		std::string net_id(const group &value_);
		float next_menu_item_index(const control &value_);
		float number_of_engines_rtd(const object &value_);
		object object_from_net_id(const std::string &value_);
		object object_parent(const object &value_);
		void on_briefing_group(const std::string &value_);
		void on_briefing_notes(const std::string &value_);
		void on_briefing_plan(const std::string &value_);
		void on_briefing_team_switch(const std::string &value_);
		bool open_dlc_page(float value_);
		bool open_map(bool value_);
		bool open_youtube_video(const std::string &value_);
		float owner(const object &value_);
		float parse_number(const std::string &value_);
		float parse_number(bool value_);
		std::string parse_text(const std::string &value_);
		void pick_weapon_pool(const object &value_);
		std::string pitch(const object &value_);
		void play_music(const std::string &value_);
		void play_sound(const std::string &value_);
		float playable_slots_number(const side &value_);
		float players_number(const side &value_);
		bool pp_effect_committed(const std::string &value_);
		bool pp_effect_committed(float value_);
		void pp_effect_destroy(float value_);
		bool pp_effect_enabled(float value_);
		float precision(const object &value_);
		bool preload_sound(const std::string &value_);
		std::string preprocess_file(const std::string &value_);
		std::string preprocess_file_line_numbers(const std::string &value_);
		std::string primary_weapon(const object &value_);
		void process_diary_link(const std::string &value_);
		void progress_loading_screen(float value_);
		float progress_position(const control &value_);
		void public_variable(const std::string &value_);
		void public_variable_server(const std::string &value_);
		void put_weapon_pool(const object &value_);
		float query_items_pool(const std::string &value_);
		float query_magazine_pool(const std::string &value_);
		float query_weapon_pool(const std::string &value_);

		std::string rank(const object &value_);
		float rank_id(const object &value_);
		float rating(const object &value_);
		void reload(const object &value_);
		bool reload_enabled(const object &value_);
		void remove_all_actions(const object &value_);
		void remove_all_assigned_items(const object &value_);
		void remove_all_containers(const object &value_);
		void remove_all_handgun_items(const object &value_);
		void remove_all_items(const object &value_);
		void remove_all_items_with_magazines(const object &value_);
		void remove_all_mission_event_handlers(const std::string &value_);
		void remove_all_music_event_handlers(const std::string &value_);
		void remove_all_primary_weapon_items(const object &value_);
		void remove_all_weapons(const object &value_);
		void remove_backpack(const object &value_);
		void remove_backpack_global(const object &value_);
		void remove_goggles(const object &value_);
		void remove_headgear(const object &value_);
		void remove_switchable_unit(const object &value_);
		void remove_uniform(const object &value_);
		void remove_vest(const object &value_);
		bool required_version(const std::string &value_);
		void reset_subgroup_direction(const object &value_);
		void restart_editor_camera(const control &value_);
		std::string role_description(const object &value_);
		bool rope_attach_enabled(const object &value_);
		object rope_attached_to(const object &value_);
		void rope_destroy(const object &value_);
		float rope_length(const object &value_);
		bool rope_unwound(const object &value_);
		void save_overlay(const control &value_);
		void save_var(const std::string &value_);
		void scope_name(const std::string &value_);
		float score(const object &value_);
		float score_side(const side &value_);
		void script_name(const std::string &value_);
		float scud_state(const object &value_);
		std::string secondary_weapon(const object &value_);
		void select_player(const object &value_);
		void selected_editor_objects(const control &value_);
		bool server_command(const std::string &value_);
		bool server_command_available(const std::string &value_);
		bool server_command_executable(const std::string &value_);
		void set_acc_time(float value_);
		void set_aperture(float value_);
		void set_armory_points(float value_);
		bool set_current_channel(float value_);

		void set_horizon_parallax_coef(float value_);
		void set_object_view_distance(float value_);
		void set_playable(const object &value_);
		void set_player_respawn_time(float value_);
		void set_shadow_distance(float value_);
		void set_simul_weather_layers(float value_);
		void set_stamina_scheme(const std::string &value_);
		void set_system_of_units(float value_);
		void set_terrain_grid(float value_);
		void set_time_multiplier(float value_);
		void set_traffic_distance(float value_);
		void set_view_distance(float value_);
		void show_chat(bool value_);
		void show_cinema_border(bool value_);
		void show_commanding_menu(const std::string &value_);
		void show_compass(bool value_);
		void show_gps(bool value_);
		void show_hud(bool value_);
		void show_map(bool value_);
		void show_pad(bool value_);
		void show_radio(bool value_);
		bool show_subtitles(bool value_);
		void show_uavfeed(bool value_);
		void show_warrant(bool value_);
		void show_watch(bool value_);
		bool simulation_enabled(const object &value_);
		float size_of(const std::string &value_);
		float skill(const object &value_);
		void skip_time(float value_);
		void sleep(float value_);
		float slider_position(const control &value_);
		float slider_position(float value_);
		bool some_ammo(const object &value_);
		std::string speaker(const object &value_);
		float speed(const object &value_);
		std::string stance(const object &value_);
		void stop_engine_rtd(const object &value_);
		bool stopped(const object &value_);
		std::string text(const std::string &value_);
		void title_fade_out(float value_);
		std::string to_lower(const std::string &value_);
		std::string to_upper(const std::string &value_);
		bool trigger_activated(const object &value_);
		object trigger_attached_vehicle(const object &value_);
		std::string trigger_text(const object &value_);
		float trigger_timeout_current(const object &value_);
		std::string trigger_type(const object &value_);
		void tv_clear(float value_);
		void tv_clear(const control &value_);
		std::string type_of(const object &value_);
		void uisleep(float value_);
		void unassign_team(const object &value_);
		void unassign_vehicle(const object &value_);
		bool underwater(const object &value_);
		std::string uniform(const object &value_);
		object uniform_container(const object &value_);
		object unit_backpack(const object &value_);
		std::string unit_pos(const object &value_);
		float unit_recoil_coefficient(const object &value_);
		bool unlock_achievement(const std::string &value_);
		void update_object_tree(const control &value_);
		object vehicle(const object &value_);
		std::string vehicle_var_name(const object &value_);
		bool verify_signature(const std::string &value_);
		std::string vest(const object &value_);
		object vest_container(const object &value_);
		float waypoint_timeout_current(const group &value_);
		bool waypoints_enabled_uav(const object &value_);
		bool weapon_lowered(const object &value_);

		void add_backpack(const object &value0_, const std::string& value1_);
		void add_backpack_global(const object &value0_, const std::string& value1_);
		void add_goggles(const object &value0_, const std::string& value1_);
		void add_handgun_item(const object &value0_, const std::string& value1_);
		void add_headgear(const object &value0_, const std::string& value1_);
		void add_item(const object &value0_, const std::string& value1_);
		void add_item_to_backpack(const object &value0_, const std::string& value1_);
		void add_item_to_uniform(const object &value0_, const std::string& value1_);
		void add_item_to_vest(const object &value0_, const std::string& value1_);
		void add_live_stats(const object &value0_, float value1_);
		void add_magazine(const object &value0_, const std::string& value1_);
		void add_magazine_global(const object &value0_, const std::string& value1_);
		void add_primary_weapon_item(const object &value0_, const std::string& value1_);
		void add_rating(const object &value0_, float value1_);
		void add_score(const object &value0_, float value1_);
		void add_score_side(const side &value0_, float value1_);
		void add_secondary_weapon_item(const object &value0_, const std::string& value1_);
		void add_uniform(const object &value0_, const std::string& value1_);
		void add_vehicle(const group &value0_, const object &value1_);
		void add_vest(const object &value0_, const std::string& value1_);
		void add_weapon(const object &value0_, const std::string& value1_);
		void add_weapon_global(const object &value0_, const std::string& value1_);
		void allow3dmode(const control &value0_, bool value1_);
		void allow_crew_in_immobile(const object &value0_, bool value1_);
		void allow_damage(const object &value0_, bool value1_);
		void allow_dammage(const object &value0_, bool value1_);
		void allow_file_operations(const control &value0_, bool value1_);
		void allow_sprint(const object &value0_, bool value1_);
		float ammo(const object &value0_, const std::string& value1_);
		float animation_phase(const object &value0_, const std::string& value1_);
		void assign_item(const object &value0_, const std::string& value1_);
		void assign_team(const object &value0_, const std::string& value1_);
		void assign_to_airport(const object &value0_, float value1_);
		void cam_command(const object &value0_, const std::string& value1_);
		void cam_commit(const object &value0_, float value1_);
		void cam_commit_prepared(const object &value0_, float value1_);
		void cam_preload(const object &value0_, float value1_);
		void cam_prepare_bank(const object &value0_, float value1_);
		void cam_prepare_dir(const object &value0_, float value1_);
		void cam_prepare_dive(const object &value0_, float value1_);
		void cam_prepare_fov(const object &value0_, float value1_);
		void cam_set_bank(const object &value0_, float value1_);
		void cam_set_dive(const object &value0_, float value1_);
		void cam_set_fov(const object &value0_, float value1_);
		void cb_set_checked(const control &value0_, bool value1_);
		void close_display(float value0_, const display &value1_);
		control controls_group_ctrl(const control &value0_, float value1_);
		display create_display(const std::string& value0_, const display &value1_);
		void create_menu(const control &value0_, float value1_);
		display create_mission_display(const std::string& value0_, const display &value1_);


		void debug_fsm(float value0_, bool value1_);
		bool diary_subject_exists(const object &value0_, const std::string& value1_);
		void direct_say(const object &value0_, const std::string& value1_);
		void disable_ai(const object &value0_, const std::string& value1_);
		void disable_conversation(const object &value0_, bool value1_);
		void disable_nvgequipment(const object &value0_, bool value1_);
		void disable_tiequipment(const object &value0_, bool value1_);
		control display_ctrl(float value0_, const display &value1_);
		void display_remove_all_event_handlers(const std::string& value0_, const display &value1_);
		float door_phase(const object &value0_, const std::string& value1_);
		float empty_positions(const object &value0_, const std::string& value1_);
		void enable_ai(const object &value0_, const std::string& value1_);
		void enable_aifeature(bool value0_, const std::string& value1_);
		void enable_aim_precision(const object &value0_, bool value1_);
		void enable_auto_start_up_rtd(const object &value0_, bool value1_);
		bool enable_auto_trim_rtd(const object &value0_, bool value1_);
		void enable_channel(float value0_, bool value1_);
		void enable_copilot(const object &value0_, bool value1_);
		void enable_fatigue(const object &value0_, bool value1_);
		void enable_mimics(const object &value0_, bool value1_);
		void enable_reload(const object &value0_, bool value1_);
		void enable_rope_attach(const object &value0_, bool value1_);
		void enable_simulation(const object &value0_, bool value1_);
		void enable_simulation_global(const object &value0_, bool value1_);
		void enable_stamina(const object &value0_, bool value1_);
		void enable_uavwaypoints(const object &value0_, bool value1_);
		void engine_on(const object &value0_, bool value1_);
		void fire(const object &value0_, const std::string& value1_);
		void fly_in_height(const object &value0_, float value1_);
		void force_add_uniform(const object &value0_, const std::string& value1_);
		void force_speed(const object &value0_, float value1_);
		void force_walk(const object &value0_, bool value1_);
		std::string get_editor_object_scope(const control &value0_, const std::string& value1_);
		float get_hit(const object &value0_, const std::string& value1_);
		float get_hit_index(const object &value0_, float value1_);
		float get_hit_point_damage(const object &value0_, const std::string& value1_);
		object get_object_proxy(const control &value0_, const std::string& value1_);
		float get_speed(const object &value0_, const std::string& value1_);
		void global_radio(const object &value0_, const std::string& value1_);
		bool has_weapon(const object &value0_, const std::string& value1_);
		void hc_remove_group(const object &value0_, const group &value1_);
		void hide_object(const object &value0_, bool value1_);
		void hide_object_global(const object &value0_, bool value1_);
		void hint_c(const std::string& value0_, const std::string& value1_);
		void html_load(const control &value0_, const std::string& value1_);
		void inflame(const object &value0_, bool value1_);
		bool is_flashlight_on(const object &value0_, const std::string& value1_);
		bool is_irlaser_on(const object &value0_, const std::string& value1_);
		bool is_kind_of(const object &value0_, const std::string& value1_);
		bool is_uniform_allowed(const object &value0_, const std::string& value1_);
		bool kb_add_database(const object &value0_, const std::string& value1_);
		bool kb_add_database_targets(const object &value0_, const std::string& value1_);
		bool kb_has_topic(const object &value0_, const std::string& value1_);
		void kb_remove_topic(const object &value0_, const std::string& value1_);
		float knows_about(const object &value0_, const side &value1_);
		void land(const object &value0_, const std::string& value1_);
		void land_at(const object &value0_, float value1_);
		std::string lb_data(const control &value0_, float value1_);
		void lb_delete(const control &value0_, float value1_);
		bool lb_is_selected(const control &value0_, float value1_);
		std::string lb_picture(const control &value0_, float value1_);
		std::string lb_picture_right(const control &value0_, float value1_);
		void lb_set_cur_sel(const control &value0_, float value1_);
		std::string lb_text(const control &value0_, float value1_);
		std::string lb_text_right(const control &value0_, float value1_);
		float lb_value(const control &value0_, float value1_);
		void leave_vehicle(const object &value0_, const group &value1_);
		void limit_speed(const object &value0_, float value1_);
		void link_item(const object &value0_, const std::string& value1_);
		float lnb_add_column(const control &value0_, float value1_);
		void lnb_delete_column(const control &value0_, float value1_);
		void lnb_delete_row(const control &value0_, float value1_);
		void lnb_set_cur_sel_row(const control &value0_, float value1_);
		bool load_identity(const object &value0_, const std::string& value1_);
		bool load_status(const object &value0_, const std::string& value1_);
		void lock(const object &value0_, bool value1_);
		void lock(const object &value0_, float value1_);
		void lock_cargo(const object &value0_, bool value1_);
		void lock_driver(const object &value0_, bool value1_);
		bool locked_cargo(const object &value0_, float value1_);
		void map_center_on_camera(const control &value0_, bool value1_);
		bool mine_detected_by(const object &value0_, const side &value1_);
		void move_object_to_end(const control &value0_, const std::string& value1_);
		void play_action(const object &value0_, const std::string& value1_);
		void play_action_now(const object &value0_, const std::string& value1_);
		void play_gesture(const object &value0_, const std::string& value1_);
		void play_move(const object &value0_, const std::string& value1_);
		void play_move_now(const object &value0_, const std::string& value1_);
		void pp_effect_commit(float value0_, const std::string& value1_);
		void pp_effect_enable(bool value0_, const std::string& value1_);
		void pp_effect_enable(float value0_, bool value1_);
		void pp_effect_force_in_nvg(float value0_, bool value1_);
		void progress_set_position(const control &value0_, float value1_);
		void public_variable_client(float value0_, const std::string& value1_);
		void radio_channel_set_call_sign(float value0_, const std::string& value1_);
		void radio_channel_set_label(float value0_, const std::string& value1_);
		bool register_task(const team_member &value0_, const std::string& value1_);
		void remove_action(const object &value0_, float value1_);
		void remove_all_event_handlers(const object &value0_, const std::string& value1_);
		void remove_all_mpevent_handlers(const object &value0_, const std::string& value1_);
		void remove_handgun_item(const object &value0_, const std::string& value1_);
		void remove_item(const object &value0_, const std::string& value1_);
		void remove_item_from_backpack(const object &value0_, const std::string& value1_);
		void remove_item_from_uniform(const object &value0_, const std::string& value1_);
		void remove_item_from_vest(const object &value0_, const std::string& value1_);
		void remove_items(const object &value0_, const std::string& value1_);
		void remove_magazine_global(const object &value0_, const std::string& value1_);
		void remove_magazines(const object &value0_, const std::string& value1_);
		void remove_menu_item(const control &value0_, float value1_);
		void remove_menu_item(const control &value0_, const std::string& value1_);
		void remove_primary_weapon_item(const object &value0_, const std::string& value1_);
		void remove_secondary_weapon_item(const object &value0_, const std::string& value1_);
		void remove_weapon(const object &value0_, const std::string& value1_);
		void remove_weapon_global(const object &value0_, const std::string& value1_);
		void reveal_mine(const object &value0_, const side &value1_);
		bool save_identity(const object &value0_, const std::string& value1_);
		bool save_status(const object &value0_, const std::string& value1_);
		void select_diary_subject(const object &value0_, const std::string& value1_);
		void select_weapon(const object &value0_, const std::string& value1_);
		void send_simple_command(const object &value0_, const std::string& value1_);
		void set_actual_collective_rtd(const object &value0_, float value1_);
		void set_airport_side(float value0_, const side &value1_);
		void set_ammo_cargo(const object &value0_, float value1_);
		void set_anim_speed_coef(const object &value0_, float value1_);
		void set_autonomous(const object &value0_, bool value1_);
		void set_bleeding_remaining(const object &value0_, float value1_);
		void set_cam_use_ti(float value0_, bool value1_);
		void set_camera_interest(const object &value0_, float value1_);
		void set_collision_light(const object &value0_, bool value1_);
		void set_combat_mode(const team_member &value0_, const std::string& value1_);
		void set_custom_aim_coef(const object &value0_, float value1_);
		void set_custom_weight_rtd(const object &value0_, float value1_);
		void set_damage(const object &value0_, float value1_);
		void set_dammage(const object &value0_, float value1_);
		void set_dir(const object &value0_, float value1_);
		void set_drop_interval(const object &value0_, float value1_);
		void set_editor_mode(const control &value0_, const std::string& value1_);
		void set_face(const object &value0_, const std::string& value1_);
		void set_faceanimation(const object &value0_, float value1_);
		void set_fatigue(const object &value0_, float value1_);
		void set_flag_side(const object &value0_, const side &value1_);
		void set_flag_texture(const object &value0_, const std::string& value1_);
		void set_formation(const team_member &value0_, const std::string& value1_);
		void set_formation_task(const object &value0_, const std::string& value1_);
		void set_from_editor(const team_member &value0_, bool value1_);
		void set_fuel(const object &value0_, float value1_);
		void set_fuel_cargo(const object &value0_, float value1_);

		void set_identity(const object &value0_, const std::string& value1_);
		void set_light_brightness(const object &value0_, float value1_);
		void set_light_day_light(const object &value0_, bool value1_);
		void set_light_flare_max_distance(const object &value0_, float value1_);
		void set_light_flare_size(const object &value0_, float value1_);
		void set_light_intensity(const object &value0_, float value1_);
		void set_light_use_flare(const object &value0_, bool value1_);

		void set_mimic(const object &value0_, const std::string& value1_);
		void set_name(const object &value0_, const std::string& value1_);
		void set_name_sound(const object &value0_, const std::string& value1_);
		bool set_owner(const object &value0_, float value1_);
		void set_oxygen_remaining(const object &value0_, float value1_);
		void set_particle_class(const object &value0_, const std::string& value1_);
		void set_pilot_light(const object &value0_, bool value1_);
		void set_pitch(const object &value0_, float value1_);
		void set_radio_msg(float value0_, const std::string& value1_);
		void set_random_lip(const object &value0_, bool value1_);
		void set_rank(const object &value0_, const std::string& value1_);
		void set_repair_cargo(const object &value0_, float value1_);
		void set_rotor_brake_rtd(const object &value0_, float value1_);
		void set_skill(const object &value0_, float value1_);
		void set_speaker(const object &value0_, const std::string& value1_);
		void set_stamina(const object &value0_, float value1_);
		void set_suppression(const object &value0_, float value1_);
		void set_target_age(const object &value0_, const std::string& value1_);
		void set_trigger_text(const object &value0_, const std::string& value1_);
		void set_trigger_type(const object &value0_, const std::string& value1_);
		void set_unconscious(const object &value0_, bool value1_);
		void set_unit_ability(const object &value0_, float value1_);
		void set_unit_pos(const object &value0_, const std::string& value1_);
		void set_unit_pos_weak(const object &value0_, const std::string& value1_);
		void set_unit_rank(const object &value0_, const std::string& value1_);
		void set_unit_recoil_coefficient(const object &value0_, float value1_);
		void set_vehicle_ammo(const object &value0_, float value1_);
		void set_vehicle_ammo_def(const object &value0_, float value1_);
		void set_vehicle_armor(const object &value0_, float value1_);
		void set_vehicle_id(const object &value0_, float value1_);
		void set_vehicle_lock(const object &value0_, const std::string& value1_);
		void set_vehicle_var_name(const object &value0_, const std::string& value1_);
		void show3dicons(const control &value0_, bool value1_);
		void show_legend(const control &value0_, bool value1_);
		float skill(const object &value0_, const std::string& value1_);
		float skill_final(const object &value0_, const std::string& value1_);
		void slider_set_position(const control &value0_, float value1_);
		void stop(const object &value0_, bool value1_);
		void suppress_for(const object &value0_, float value1_);
		void switch_action(const object &value0_, const std::string& value1_);
		void switch_camera(const object &value0_, const std::string& value1_);
		void switch_gesture(const object &value0_, const std::string& value1_);
		void switch_light(const object &value0_, const std::string& value1_);
		void switch_move(const object &value0_, const std::string& value1_);
		void trigger_attach_object(const object &value0_, float value1_);
		std::string tv_tooltip(const control &value0_, float value1_);
		void unassign_item(const object &value0_, const std::string& value1_);
		void unlink_item(const object &value0_, const std::string& value1_);
		bool unregister_task(const team_member &value0_, const std::string& value1_);
		void use_audio_time_for_moves(const object &value0_, bool value1_);
		void vehicle_radio(const object &value0_, const std::string& value1_);

		void delete_team(const team_member &value_);
		void do3denaction(const std::string& value_);
		std::string formation(const team_member &value_);
		bool from_editor(const team_member &value_);
		void get3dengrid(const std::string& value_);
		bool is_agent(const team_member &value_);
		team_member leader(const team_member &value_);
		std::string team_name(const team_member &value_);
		std::string team_type(const team_member &value_);

		float radio_volume();
		void save_game();
		void save_joysticks();
		side side_enemy();
		side side_friendly();
		side side_logic();
		side side_unknown();
		team_member team_member_null();
		side west();
		bool buldozer_is_enabled_road_diag();
		void buldozer_reload_oper_map();
		void cancel_simple_task_destination(task value_);
		task current_task(const object &value_);
		script exec_vm(const std::string& value_);
		float priority(task value_);
		bool script_done(script value_);
		bool task_completed(task value_);
		task task_parent(task value_);
		std::string task_state(task value_);
		void terminate(script value_);
		std::string type(task value_);
	}
}
