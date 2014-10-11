<?php if ( ! defined('BASEPATH')) exit('No direct script access allowed');

class Webservices_model extends CI_Model {

	function __construct()
	{
		parent:: __construct();
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

	function get_last_quest($token)
	{
		$this->db->select('*');
		$this->db->from('request');
		$this->db->where('server_key', $token);
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

	function add_track_value($array)
	{
		$this->db->insert('info_server', $array);
		return ($this->db->insert_id());
	}
}