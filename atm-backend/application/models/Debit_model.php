<?php
/**
 *
 */
class Debit_model extends CI_model
{
  function get_debit($id){
    $this->db->select('*');
    $this->db->from('d_account');
    if($id !== NULL) {
      $this->db->where('da_id',$id);
    }
    return $this->db->get()->result_array();
  }
  function add_debit($add_data){
    $this->db->insert('d_account',$add_data);
    if($this->db->affected_rows()>0){
      return TRUE;
      //return $this->db->insert_id(); 
    }
    else {
      return FALSE;
    }  
  }
  function update_debit($id, $update_data){
    $this->db->where('da_id',$id);
    $this->db->update('d_account',$update_data);
    if($this->db->affected_rows()>0){
      return TRUE; 
    }
    else {
      return FALSE;
    }
  }

  function delete_debit($id){
    $this->db->where('da_id',$id);
    $this->db->delete('d_account');
    if($this->db->affected_rows()>0){
      return TRUE; 
    }
    else {
      return FALSE;
    }
  }


}
