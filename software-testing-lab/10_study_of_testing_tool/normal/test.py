from selenium import webdriver
import time
browser=webdriver.Chrome("C:\Python27\Scripts\chromedriver.exe")
browser.get("http:\\letskodeit.teachable.com\pages\practice")
browser.maximize_window()
parenthandle=browser.current_window_handle
print("parent handle is" + parenthandle)
browser.find_element_by_id("openwindow").click()
time.sleep(2)
handles=browser.window_handles
for handle in handles:
    print(handle)
if handle not in parenthandle:
    browser.switch_to_window(handle)
browser.maximize_window()
browser.find_element_by_css_selector("body > div > div > div > div.row.course-list.list > div:nth-child(2) > div > div.row > a > div > div.course-listing-title").click()
