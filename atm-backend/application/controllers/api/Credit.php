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
class Credit extends REST_Controller {

    function __construct()
    {
        //enable cors
        header('Access-Control-Allow-Origin: *');
        header("Access-Control-Allow-Methods: GET, POST, OPTIONS, PUT, DELETE");
        // Construct the parent class
        parent::__construct();

        $this->load->model('Credit_model');
    }

    public function credit_get()
    {
        // book from a data store e.g. database  

        $id = $this->get('id');

        // If the id parameter doesn't exist return all books
        if ($id === NULL)
        {
            $credit=$this->Credit_model->get_credit(NULL);
            // Check if the book data store contains book (in case the database result returns NULL)
            if ($credit)
            {
                // Set the response and exit
                $this->response($credit, REST_Controller::HTTP_OK); // OK (200) being the HTTP response code
            }
            else
            {
                // Set the response and exit
                $this->response([
                    'status' => FALSE,
                    'message' => 'No credit account was found'
                ], REST_Controller::HTTP_NOT_FOUND); // NOT_FOUND (404) being the HTTP response code
            }
        }

         // Find and return a single record for a particular credit account.
        else {
            // Validate the id.
            if ($id <= 0)
            {
                // Invalid id, set the response and exit.
                $this->response(NULL, REST_Controller::HTTP_BAD_REQUEST); // BAD_REQUEST (400) being the HTTP response code
            }

            // Get the credit account from the database, using the id as key for retrieval.
            $credit=$this->Credit_model->get_debit($id);
            if (!empty($credit))
            {
                $this->set_response($credit, REST_Controller::HTTP_OK); // OK (200) being the HTTP response code
            }
            else
            {
                $this->set_response([
                    'status' => FALSE,
                    'message' => 'credit account could not be found'
                ], REST_Controller::HTTP_NOT_FOUND); // NOT_FOUND (404) being the HTTP response code
            }
        }

    }

    public function credit_post()
    {
        // Add a new credit account
        $add_data=array(
          'ca_id'=>$this->post('ca_id'),
          'c_balance'=>$this->post('c_balance'),
          'c_limit'=>$this->post('c_limit')
        );
        $insert_id=$this->Credit_model->add_credit($add_data);
        if($insert_id)
        {
            $message = [
                'ca_id'=>$this->post('ca_id'),
                'c_balance'=>$this->post('c_balance'),
                'c_limit'=>$this->post('c_limit'),
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
    public function credit_put()
    {
        // Update the credit account
        $id=$this->get('id');
        $update_data=array(
            // 'ca_id'=>$this->put('ca_id'),
            'c_balance'=>$this->put('c_balance'),
            'c_limit'=>$this->put('c_limit')
        );
        $result=$this->Credit_model->update_credit($id, $update_data);

        if($result)
        {
            $message = [
                'ca_id'=>$id,
                'c_balance'=>$this->put('c_balance'),
                'c_limit'=>$this->put('c_limit'),
                'message' => 'Updated a resource'
            ];

            $this->set_response($message, REST_Controller::HTTP_CREATED); // CREATED (201) being the HTTP response code
        }
        else 
        {
            // Set the response and exit
            $this->response([
                'status' => FALSE,
                'message' => 'Can not update data',
            ], REST_Controller::HTTP_CONFLICT); // CAN NOT CREATE (409) being the HTTP response code
        }
    }

    public function credit_delete()
    {
        $id = $this->get('id');

        // Validate the id.
        if ($id <= 0)
        {
            // Set the response and exit
            $this->response(NULL, REST_Controller::HTTP_BAD_REQUEST); // BAD_REQUEST (400) being the HTTP response code
        }
        $result=$this->Credit_model->delete_credit($id);
        if ($result)
        {
          $message = [
              'ca_id' => $id,
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
