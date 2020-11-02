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
class Transaction extends REST_Controller {

    function __construct()
    {
        //enable cors
        header('Access-Control-Allow-Origin: *');
        header("Access-Control-Allow-Methods: GET, POST, OPTIONS, patch, PATCH, DELETE");
        // Construct the parent class
        parent::__construct();

        $this->load->model('Transaction_model');
    }

    public function transaction_get()
    {
        // book from a data store e.g. database  

        $id = $this->get('id');

        // If the id parameter doesn't exist return all books
        if ($id === NULL)
        {
            $transaction=$this->Transaction_model->get_tr(NULL);
            // Check if the db contains transaction (in case the database result returns NULL)
            if ($transaction)
            {
                // Set the response and exit
                $this->response($transaction, REST_Controller::HTTP_OK); // OK (200) being the HTTP response code
            }
            else
            {
                // Set the response and exit
                $this->response([
                    'status' => FALSE,
                    'message' => 'No transaction was found'
                ], REST_Controller::HTTP_NOT_FOUND); // NOT_FOUND (404) being the HTTP response code
            }
        }

         // Find and return a single record for a particular transaction.
        else {
            // Validate the id.
            if ($id <= 0)
            {
                // Invalid id, set the response and exit.
                $this->response(NULL, REST_Controller::HTTP_BAD_REQUEST); // BAD_REQUEST (400) being the HTTP response code
            }

            // Get the transaction from the database, using the id as key for retrieval.
            $transaction=$this->Transaction_model->get_tr($id);
            if (!empty($transaction))
            {
                $this->set_response($transaction, REST_Controller::HTTP_OK); // OK (200) being the HTTP response code
            }
            else
            {
                $this->set_response([
                    'status' => FALSE,
                    'message' => 'transaction could not be found'
                ], REST_Controller::HTTP_NOT_FOUND); // NOT_FOUND (404) being the HTTP response code
            }
        }

    }

    public function transaction_post()
    {
        // Add a new transaction
        $add_data=array(
          'acc_id'=>$this->post('acc_id'),
          'amount'=>$this->post('amount')
        );
        $insert_id=$this->Transaction_model->add_tr($add_data);
        if($insert_id)
        {
            $message = [
                'tr_id' => $insert_id,
                'acc_id' => $this->post('acc_id'),
                'amount'=>$this->post('amount'),
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
    public function transaction_patch()
    {
        // Update the transaction
        $id=$this->get('id');
        $update_data=array(
            'acc_id'=>$this->patch('acc_id'),
            'amount'=>$this->patch('amount'),
            // 'time'=>$this->patch('time')
        );
        $result=$this->Transaction_model->update_tr($id, $update_data);

        if($result)
        {
            $message = [
                'tr_id'=>$id,
                'acc_id'=>$this->patch('acc_id'),
                'amount'=>$this->patch('amount'),
                    // 'time'=>$this->patch('time'),
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

    public function card_delete()
    {
        $id = $this->get('id');

        // Validate the id.
        if ($id <= 0)
        {
            // Set the response and exit
            $this->response(NULL, REST_Controller::HTTP_BAD_REQUEST); // BAD_REQUEST (400) being the HTTP response code
        }
        $result=$this->Transaction_model->delete_card($id);
        if ($result)
        {
          $message = [
              'tr_id' => $id,
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
