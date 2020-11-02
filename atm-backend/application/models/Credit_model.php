<?php
/**
 *
 */
class Credit_model extends CI_model
{
  function get_credit($id){
    $this->db->select('*');
    $this->db->from('c_account');
    if($id !== NULL) {
      $this->db->where('ca_id',$id);
    }
    return $this->db->get()->result_array();
  }
  function add_credit($add_data){
    $this->db->insert('c_account',$add_data);
    if($this->db->affected_rows()>0){
      return TRUE;
      //return $this->db->insert_id(); 
    }
    else {
      return FALSE;
    }  
  }
  function update_credit($id, $update_data){
    $this->db->where('ca_id',$id);
    $this->db->update('c_account',$update_data);
    if($this->db->affected_rows()>0){
      return TRUE; 
    }
    else {
      return FALSE;
    }
  }

  function delete_credit($id){
    $this->db->where('ca_id',$id);
    $this->db->delete('c_account');
    if($this->db->affected_rows()>0){
      return TRUE; 
    }
    else {
      return FALSE;
    }
  }


}
