from selenium import webdriver

EMAIL = input("Enter email:")
PASSWORD = input("Enter password:")

driver = webdriver.Edge('msedgedriver.exe')

driver.get('https://webmail.healthbc.org/my.policy')

user_input = driver.find_element_by_id('input_1')
user_input.send_keys(EMAIL)

password_input = driver.find_element_by_id('input_2')
password_input.send_keys(PASSWORD)

login_btn = driver.find_element_by_id('submit_row')

login_btn.click()
