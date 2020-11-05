<?php
/**
 *
 */
class Card_model extends CI_model
{
  function get_card($id){
    $this->db->select('card_id, pin, owner, card.da_id, card.ca_id, d_account.*, c_account.*');
    $this->db->from('card');
    $this->db->join('d_account', 'd_account.da_id = card.da_id');
    $this->db->join('c_account', 'c_account.ca_id = card.ca_id');
    // $this->db->on('card.card_id=d_account.da_id');
    if($id !== NULL) {
      $this->db->where('card_id',$id);
    }
    return $this->db->get()->result_array();
  }
  function add_card($add_data){
    $this->db->insert('card',$add_data);
    if($this->db->affected_rows()>0){
      return TRUE;
      //return $this->db->insert_id(); 
    }
    else {
      return FALSE;
    }  
  }
  function update_card($id, $update_data){
    $this->db->where('card_id',$id);
    $this->db->update('card',$update_data);
    if($this->db->affected_rows()>0){
      return TRUE; 
    }
    else {
      return FALSE;
    }
  }

  function delete_card($id){
    $this->db->where('card_id',$id);
    $this->db->delete('card');
    if($this->db->affected_rows()>0){
      return TRUE; 
    }
    else {
      return FALSE;
    }
  }

  function check_login($cardid){
    $this->db->select('pin');
    $this->db->from('card');
    $this->db->where('card_id',$cardid);
    return $this->db->get()->row('pin');
  }


}
