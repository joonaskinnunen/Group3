<?php

defined('BASEPATH') OR exit('No direct script access allowed');

// This can be removed if you use __autoload() in config.php OR use Modular Extensions
/** @noinspection PhpIncludeInspection */
require APPPATH . 'libraries/REST_Controller.php';

/**
 * This is an example of a RestApi based on PHP and CodeIgniter 3.
 *
 *
 * @package         CodeIgniter
 * @subpackage      Rest Server
 * @category        Controller
 * @author          Pekka Alaluukas (edited the version made by Phil Sturgeon & Chris Kacerguis)
 * @license         MIT
 * @link            https://github.com/chriskacerguis/codeigniter-restserver
 */
class Card extends REST_Controller {

    function __construct()
    {
        //enable cors
        header('Access-Control-Allow-Origin: *');
        header("Access-Control-Allow-Methods: GET, POST, OPTIONS, PUT, DELETE");
        // Construct the parent class
        parent::__construct();

        $this->load->model('Card_model');
    }

    public function card_get()
    {
        // card from a data store e.g. database

        $id = $this->get('id');

        // If the id parameter doesn't exist return all users
        if ($id === NULL)
        {
            $card=$this->Card_model->get_card(NULL);
            // Check if the card data store contains card (in case the database result returns NULL)
            if ($card)
            {
                // Set the response and exit
                $this->response($card, REST_Controller::HTTP_OK); // OK (200) being the HTTP response code
            }
            else
            {
                // Set the response and exit
                $this->response([
                    'status' => FALSE,
                    'message' => 'No card were found'
                ], REST_Controller::HTTP_NOT_FOUND); // NOT_FOUND (404) being the HTTP response code
            }
        }

         // Find and return a single record for a particular card.
        else {
            // Validate the id.
            if ($id <= 0)
            {
                // Invalid id, set the response and exit.
                $this->response(NULL, REST_Controller::HTTP_BAD_REQUEST); // BAD_REQUEST (400) being the HTTP response code
            }

            // Get the card from the database, using the id as key for retrieval.
            $card=$this->Card_model->get_card($id);
            if (!empty($card))
            {
                $this->set_response($card, REST_Controller::HTTP_OK); // OK (200) being the HTTP response code
            }
            else
            {
                $this->set_response([
                    'status' => FALSE,
                    'message' => 'card could not be found'
                ], REST_Controller::HTTP_NOT_FOUND); // NOT_FOUND (404) being the HTTP response code
            }
        }

    }

    public function card_post()
    {
        // Add a new card
        $clear_pin=$this->post('pin');
        $encrypted_pin = password_hash($clear_pin,PASSWORD_DEFAULT);
        $add_data=array(
          'card_id'=>$this->post('card_id'),
          'pin'=>$encrypted_pin,
          'owner'=>$this->post('owner'),
          'da_id'=>$this->post('da_id'),
          'ca_id'=>$this->post('ca_id')
        );
        $insert_id=$this->Card_model->add_card($add_data);
        if($insert_id)
        {
            $message = [
                'card_id' => $this->post('card_id'),
                'pin' => $this->post('pin'),
                'owner' => $this->post('owner'),
                'da_id'=>$this->post('da_id'),
                'ca_id'=>$this->post('ca_id'),
                'message' => 'Added a resource'
            ];
            $this->set_response($message, REST_Controller::HTTP_CREATED); // CREATED (201) being the HTTP response code
        }
        else
        {
            // Set the response and exit
            $this->response([
                'status' => FALSE,
                'message' => 'Can not add data'
            ], REST_Controller::HTTP_CONFLICT); // CAN NOT CREATE (409) being the HTTP response code
        }

    }
    public function card_put()
    {
        // Update the card
        $id=$this->get('id');
        $clear_pin=$this->put('pin');
        $encrypted_pin = password_hash($clear_pin,PASSWORD_DEFAULT);
        $update_data=array(
            'pin'=>$encrypted_pin,
            'owner'=>$this->put('owner'),
            'da_id'=>$this->put('da_id'),
            'ca_id'=>$this->put('ca_id')
        );
        $result=$this->Card_model->update_card($id, $update_data);

        if($result)
        {
          $message = [
            'card_id' => $id,
            'owner'=>$this->put('owner'),
            'pin'=>$encrypted_pin,
            'da_id'=>$this->put('da_id'),
            'ca_id'=>$this->put('ca_id'),
            'message' => 'Updated a resource'
          ];

            $this->set_response($message, REST_Controller::HTTP_CREATED); // CREATED (201) being the HTTP response code
        }
        else
        {
            // Set the response and exit
            $this->response([
                'card_id' => $id,
                'owner'=>$this->put('owner'),
                'pin'=>$encrypted_pin,
                'da_id'=>$this->put('da_id'),
                'ca_id'=>$this->put('ca_id'),
                'status' => FALSE,
                'message' => 'Can not update data'
            ], REST_Controller::HTTP_CONFLICT); // CAN NOT CREATE (409) being the HTTP response code
        }
    }

    public function card_delete()
    {
        $id = $this->get('id');

        // Validate the id.
        if ($id <= 0)
        {
            // Set the response and exit
            $this->response(NULL, REST_Controller::HTTP_BAD_REQUEST); // BAD_REQUEST (400) being the HTTP response code
        }
        $result=$this->Card_model->delete_card($id);
        if ($result)
        {
          $message = [
              'card_id' => $id,
              'message' => 'Deleted the resource'
          ];
          $this->set_response($message, REST_Controller::HTTP_OK);
        }
        else
        {
            // Set the response and exit
            $this->response([
                'status' => FALSE,
                'message' => 'Can not delete data'
            ], REST_Controller::HTTP_CONFLICT); // CAN NOT CREATE (409) being the HTTP response code
        }
    }



}
