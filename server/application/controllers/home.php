<?php if ( ! defined('BASEPATH')) exit('No direct script access allowed');

class Home extends CI_Controller {

	function __construct()
	{
		parent:: __construct();
		$this->load->model('Webservices_model');
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

		$this->load->view('view', $this->data);
	}

	public function index()
	{
		$this->load->view('index');
	}

	public function index_mobile()
	{
		$this->load->view('index_mobile');
	}

}