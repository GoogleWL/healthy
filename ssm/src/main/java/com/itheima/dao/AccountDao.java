package com.itheima.dao;

import com.itheima.pojo.Account;
import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Select;
import org.springframework.stereotype.Repository;

import java.util.List;

/**
 * 账户dao接口
 * @author JuJueZhe
 */
@Repository
public interface AccountDao {

 /**
  * 查询所有账户信息
  * @return
  */
 @Select("select * from account ")
 public List<Account> findAll();

 /**
  * 保存账户信息
  * @param account
  */
 @Insert("insert into account(name,money) values (#{name},#{money})")
 public void saveAccount(Account account);
}
