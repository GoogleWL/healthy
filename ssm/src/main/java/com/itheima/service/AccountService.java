package com.itheima.service;

import com.itheima.pojo.Account;

import java.util.List;

/**
 * @author JuJueZhe
 */
public interface AccountService {
 /**
  * 查询所有账户信息
  * @return
  */
 public List<Account> findAll();

 /**
  * 保存账户信息
  * @param account
  */
 public void saveAccount(Account account);
}
