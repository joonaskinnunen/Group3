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
class Debit extends REST_Controller {

    function __construct()
    {
        //enable cors
        header('Access-Control-Allow-Origin: *');
        header("Access-Control-Allow-Methods: GET, POST, OPTIONS, PUT, DELETE");
        // Construct the parent class
        parent::__construct();

        $this->load->model('Debit_model');
    }

    public function debit_get()
    {
        // book from a data store e.g. database  

        $id = $this->get('id');

        // If the id parameter doesn't exist return all books
        if ($id === NULL)
        {
            $debit=$this->Debit_model->get_debit(NULL);
            // Check if the book data store contains book (in case the database result returns NULL)
            if ($debit)
            {
                // Set the response and exit
                $this->response($debit, REST_Controller::HTTP_OK); // OK (200) being the HTTP response code
            }
            else
            {
                // Set the response and exit
                $this->response([
                    'status' => FALSE,
                    'message' => 'No debit account was found'
                ], REST_Controller::HTTP_NOT_FOUND); // NOT_FOUND (404) being the HTTP response code
            }
        }

         // Find and return a single record for a particular debit account.
        else {
            // Validate the id.
            if ($id <= 0)
            {
                // Invalid id, set the response and exit.
                $this->response(NULL, REST_Controller::HTTP_BAD_REQUEST); // BAD_REQUEST (400) being the HTTP response code
            }

            // Get the debit account from the database, using the id as key for retrieval.
            $debit=$this->Debit_model->get_debit($id);
            if (!empty($debit))
            {
                $this->set_response($debit, REST_Controller::HTTP_OK); // OK (200) being the HTTP response code
            }
            else
            {
                $this->set_response([
                    'status' => FALSE,
                    'message' => 'debit account could not be found'
                ], REST_Controller::HTTP_NOT_FOUND); // NOT_FOUND (404) being the HTTP response code
            }
        }

    }

    public function debit_post()
    {
        // Add a new debit account
        $add_data=array(
          'da_id'=>$this->post('da_id'),
          'd_balance'=>$this->post('d_balance')
        );
        $insert_id=$this->Debit_model->add_debit($add_data);
        if($insert_id)
        {
            $message = [
              //  'id_book' => $insert_id,
                'da_id'=>$this->post('da_id'),
                'd_balance'=>$this->post('d_balance'),
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
    public function debit_put()
    {
        // Update the debit account
        $id=$this->get('id');
        $update_data=array(
            'd_balance'=>$this->put('d_balance')
        );
        $result=$this->Debit_model->update_debit($id, $update_data);

        if($result)
        {
            $message = [
                'da_id'=>$id,
                'd_balance'=>$this->put('d_balance'),
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
                'id' => $id,
                'd_balance' => $this->put('d_balance')
            ], REST_Controller::HTTP_CONFLICT); // CAN NOT CREATE (409) being the HTTP response code
        }
    }

    public function debit_delete()
    {
        $id = $this->get('id');

        // Validate the id.
        if ($id <= 0)
        {
            // Set the response and exit
            $this->response(NULL, REST_Controller::HTTP_BAD_REQUEST); // BAD_REQUEST (400) being the HTTP response code
        }
        $result=$this->Debit_model->delete_debit($id);
        if ($result)
        {
          $message = [
              'da_id' => $id,
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
