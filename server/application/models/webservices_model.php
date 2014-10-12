<?php if ( ! defined('BASEPATH')) exit('No direct script access allowed');

class Webservices_model extends CI_Model {

	function __construct()
	{
		parent:: __construct();
	}

	function get_all_track()
	{
		$this->db->select('*');
		$this->db->from('tracker');
		return ($this->db->get()->result());
	}

	function val_serv($key, $array)
	{
		$this->db->set($array);
		$this->db->where('key', $key);
		$this->db->update('server');
	}

	function del_serv($token) {
		$this->db->where('key', $token);
		$this->db->delete('server'); 
	}

	function del_req($token) {
		$this->db->where('server_key', $token);
		$this->db->delete('request'); 
	}

	function del_ent($token) {
		$this->db->where('server_key', $token);
		$this->db->delete('info_server'); 
	}

	function get_serv_z()
	{
		$this->db->select('*');
		$this->db->from('server');
		$this->db->where('state', 0);
		return ($this->db->get()->result());
	}

	function get_serv()
	{
		$this->db->select('*');
		$this->db->from('server');
		$this->db->where('state', 1);
		$this->db->order_by('id', 'asc');
		return ($this->db->get()->result());
	}

	function get_one_serv($token)
	{
		$this->db->select('*');
		$this->db->from('server');
		$this->db->where('key', $token);
		return ($this->db->get()->row());
	}

	function get_tracker($token)
	{
		$this->db->select('*');
		$this->db->from('info_server');
		$this->db->where('server_key', $token);
		return ($this->db->get()->result());
	}

	function get_all_value()
	{
		$this->db->select('*');
		$this->db->from('info_server');
		// $this->db->where('server_key', $token);
		return ($this->db->get()->result());
	}

	function get_view_token($token)
	{
		$this->db->select('*');
		$this->db->from('current_view');
		$this->db->where('token', $token);
		return ($this->db->get()->row());
	}

	function change_view($token, $array)
	{
		$this->db->set($array);
		$this->db->where('id', $token);
		$this->db->update('current_view');
	}

	function remove_quest($id)
	{
		$this->db->where('id', $id);
		$this->db->delete('request');
	}

	function get_client()
	{
		$this->db->select('*');
		$this->db->from('server');
		$this->db->where('state', 1);
		return ($this->db->get()->result());
	}

	function get_config($config)
	{
		$this->db->select('*');
		$this->db->from('config_server');
		$this->db->where('name', 'default');
		return ($this->db->get()->row());
	}

	function get_last_quest($token)
	{
		$this->db->select('*');
		$this->db->from('request');
		$this->db->where('server_key', $token);
		$this->db->order_by('id', 'asc');
		return ($this->db->get()->result());
	}

	function check_token($token)
	{
		$this->db->select('*');
		$this->db->from('server');
		$this->db->where('key', $token);
		$this->db->where('state', 1);
		return ($this->db->get()->row());
	}

	function add_new_server($array)
	{
		$this->db->insert('server', $array);
		return ($this->db->insert_id());
	}

	function add_quest($array)
	{
		$this->db->insert('request', $array);
		return ($this->db->insert_id());
	}

	function check_old_value($token, $type)
	{
		$this->db->select('*');
		$this->db->from('info_server');
		$this->db->where('server_key', $token);
		$this->db->where('type', $type);
		return ($this->db->get()->row());
	}

	function edit_track_value($id, $array)
	{
		$this->db->set($array);
		$this->db->where('id', $id);
		$this->db->update('info_server');
	}

	function add_track_value($array)
	{
		$this->db->insert('info_server', $array);
		return ($this->db->insert_id());
	}
}