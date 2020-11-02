<?php
/**
 *
 */
class Transaction_model extends CI_model
{
//   function get_tr($id){
//     $this->db->select('*');
//     $this->db->from('transaction');
//     if($id !== NULL) {
//       $this->db->where('tr_id',$id);
//     }
//     return $this->db->get()->result_array();
//   }

  // TIMESTAMP as UNIX epoch time
  function get_tr($id){
    $this->db->select('tr_id, acc_id, amount, unix_timestamp(time) as time');
    $this->db->from('transaction');
    if($id !== NULL) {
      $this->db->where('tr_id',$id);
    }
    return $this->db->get()->result_array();
  }

  function add_tr($add_data){
    $this->db->insert('transaction',$add_data);
    if($this->db->insert_id()!==NULL){
      return $this->db->insert_id(); 
    }
    else {
      return FALSE;
    }  
  }
  function update_tr($id, $update_data){
    $this->db->where('tr_id',$id);
    $this->db->update('transaction',$update_data);
    if($this->db->affected_rows()>0){
      return TRUE; 
    }
    else {
      return FALSE;
    }
  }

  function delete_tr($id){
    $this->db->where('tr_id',$id);
    $this->db->delete('transaction');
    if($this->db->affected_rows()>0){
      return TRUE; 
    }
    else {
      return FALSE;
    }
  }


}
