<?php if ( ! defined('BASEPATH')) exit('No direct script access allowed');

class API extends CI_Controller {

	function __construct()
	{
		parent:: __construct();
		$this->load->model('Webservices_model');
	}

	public function send_info_server($token)
	{
		if (!$token)
			$this->_show_error("665", "Invalid Arguments");
		if ($this->_token_autentif($token))
		{
			$quest = $this->Webservices_model->get_last_quest($token);
			foreach ($quest as $q) {
				echo $q->request . '</br>';
				$this->Webservices_model->remove_quest($q->id);
			}
			exit();
		}
		else
			$this->_show_error("666", "Invalid Token");
	}

	public function push_track($token = false, $type = false, $value = false)
	{
		if (!$token || !$type || !$value)
			$this->_show_error("665", "Invalid Arguments");
		if ($this->_token_autentif($token))
		{
			$array = array(	'server_key' => $token,
							'type' => $type,
							'value' => $value);
			$this->Webservices_model->add_track_value($array);
			echo 'ok';
			exit();
		}
		else
			$this->_show_error("666", "Invalid Token");
	}

	public function add_new_client()
	{
		$ip = ($_SERVER['REMOTE_ADDR']) ? $_SERVER['REMOTE_ADDR'] : '';
		$key = md5(uniqid());
		$array = array(	'host' => $ip,
						'key' => $key,
						'last_request' => date("Y-m-d H:i:s"),
						'name' => $ip,
						'state' => 0);
		$id = $this->Webservices_model->add_new_server($array);

		// $this->_add_default_param($key);

		$ret = array('return' => 'success', 'app_key' => $key);
		echo $key;
		exit();
	}

	//PRIVATE METHOD

	private function _token_autentif($token)
	{
		$ret = $this->Webservices_model->check_token($token);
		if ($ret)
			return (true);
		else
			return (false);
	}

	private function _show_error($type, $content)
	{
		echo 'ko:'.$type.':'.$content;
		exit();
	}

	private function _add_default_param($key)
	{
		$config = $this->Webservices_mode->get_config("default");
	}

	private function _show_json($json)
	{
		header('Content-Type: application/json');
		echo json_encode($json);
		exit();
	}

}

/* End of file welcome.php */
/* Location: ./application/controllers/welcome.php */