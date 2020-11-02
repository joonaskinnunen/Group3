<?php
defined('BASEPATH') OR exit('No direct script access allowed');

class Login extends CI_Controller {

    public function check_login(){
        $this->load->model('Card_model');
        $cardid=$this->input->get('card_id');
        $plaintext_pin=$this->input->get('pin');
        $encrypted_pin=$this->Card_model->check_login($cardid);

        if(password_verify($plaintext_pin,$encrypted_pin)){
          $result=true;
        }
        else{
          $result=false;
        }
        echo json_encode($result);
    }
}
