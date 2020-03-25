package com.itheima.service.impl;

import com.itheima.dao.AccountDao;
import com.itheima.pojo.Account;
import com.itheima.service.AccountService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

/**
 * @author JuJueZhe
 */
@Service("accountService")
public class AccountServiceImpl implements AccountService {

 @Autowired
 private AccountDao accountDao;
 @Override
 public List<Account> findAll() {
  System.out.println("业务层，查询所有账户...");
  return accountDao.findAll();
 }

 @Override
 public void saveAccount(Account account) {
  System.out.println("业务层，保存账户...");
  accountDao.saveAccount(account);

 }
}
