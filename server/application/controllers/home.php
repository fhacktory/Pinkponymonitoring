<?php if ( ! defined('BASEPATH')) exit('No direct script access allowed');

class Home extends CI_Controller {

	function __construct()
	{
		parent:: __construct();
		$this->load->model('Webservices_model');
	}

	public function get_tracker($token)
	{
		if ($this->_token_autentif($token)) {
			$tracker = $this->Webservices_model->get_tracker($token);
			echo json_encode($tracker);
			exit();
		}
	}

	public function del_track_edit($token, $type)
	{
		$array =  array('server_key' => $token, $request => 'del '.$type);
		$this->Webservices_model->add_quest($array);
		sleep(5);
		$this->Webservices_model->del_track($token, $type);
		$ret = array('ret' => 'success');
		echo json_encode($ret);
		exit();
	}

	public function add_new_track($track, $token)
	{
		$array = array('server_key' => $token, 'request' => 'add '.$track);
		$array2 = array('server_key' => $token, 'type' => $track, 'value' => 0);
		$this->Webservices_model->add_quest($array);
		$id = $this->Webservices_model->add_track_value($array2);
		$ret = array('ret' => 'success');
		echo json_encode($ret);
		exit();
	}

	public function change_name($name, $token)
	{
		$array = array('name' => $name);
		$this->Webservices_model->val_serv($token, $array);
		$ret = array('ret' => 'success');
		echo json_encode($ret);
		exit();
	}

	public function edit($token)
	{
		$this->data['all_t'] = $this->Webservices_model->get_all_track();
		$this->data['client'] = $this->Webservices_model->get_one_serv($token);
		$this->data['track'] = $this->Webservices_model->get_tracker($token);
		$this->data['nb_track'] = count($this->data['track']);
		$this->load->view('edit', $this->data);
	}

	public function val_server($token)
	{
		$array = array('state' => 1);
		$this->Webservices_model->val_serv($token, $array);
		redirect('home/admin');
	}

	public function remove_server($token)
	{
		$this->Webservices_model->del_serv($token);
		$this->Webservices_model->del_ent($token);
		$this->Webservices_model->del_req($token);
		redirect('home/admin');
	}

	public function admin()
	{
		$this->data['serv_z'] = $this->Webservices_model->get_serv_z();
		$this->data['nb_serv_z'] = count($this->data['serv_z']);
		$this->data['serv'] = $this->Webservices_model->get_serv();
		$this->data['nb_serv'] = count($this->data['serv']);
		$this->load->view('administration', $this->data);
	}

	public function get_all_val()
	{
		$data = $this->Webservices_model->get_all_value();
		$i = 0;
		foreach ($data as $d) {
			$json['val'.$i] = $d;
			$i++;
		}
		echo json_encode($json);
	}

	public function check_view()
	{
		$data = $this->Webservices_model->get_view_token("f26cc976eac8f684f0f3be3a6fd629b9");
		$ret = array('ret' => $data->view, 'token' =>$data->token);
		echo json_encode($ret);
		exit();
	}

	public function change_view($token, $view)
	{
		echo 'Change View';
		$data = $this->Webservices_model->get_view_token($token);
  		$array = array('view' => $view);
		$this->Webservices_model->change_view($data->id, $array);
		$ret = array('ret' => 'success');
		echo json_encode($ret);
		exit();
	}

	public function view($token, $view)
	{
		
		$this->data['token'] = $token;
		$this->data['view'] = $view;

		$client = $this->Webservices_model->get_serv();
		$i = 1;
		foreach ($client as $c) {
			if ($i == $view) {
				$this->data['client'] = $this->Webservices_model->get_one_serv($c->key);
				$this->data['track'] = $this->Webservices_model->get_tracker($c->key);
			}
			$i++;
		}
		$this->load->view('fiche', $this->data);
	}

	public function index()
	{
		$this->data['token'] = "f8b89ed0edb6f9ef9f394c5da6dd2241";
		$this->data['client'] = $this->Webservices_model->get_client();
		$this->load->view('index', $this->data);
	}

	public function index_mobile($token = "null")
	{
		if ($token == "f8b89ed0edb6f9ef9f394c5da6dd2241") {
			$this->data['token'] = $token;
			$this->data['server'] = $this->Webservices_model->get_serv();
			$this->data['aut'] = 1;
			$this->load->view('index_mobile', $this->data);
		}
		else
		{
			$array = array('return' => 'error', 'value' => 'Token is Null or invalid');
			echo json_encode($array);
			exit();
		}
	}

	private function _token_autentif($token)
	{
		$ret = $this->Webservices_model->check_token($token);
		if ($ret)
			return (true);
		else
			return (false);
	}

}