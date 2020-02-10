from selenium import webdriver
import time
import xlrd
browser = webdriver.Chrome("C:\Python27\Scripts\chromedriver.exe")
browser.get("http:\\google.com")
browser.maximize_window()
wb = xlrd.open_workbook('sv.xlsx')
print "Excel File imported"
sheetname = wb.sheet_names()
sh1 = wb.sheet_by_index(0)
i = 0
while (i < 4):
            rownum = (i)
            rows = sh1.row_values(rownum)
            element = browser.find_element_by_css_selector("#tsf > div:nth-child(2) > div.A8SBwf > div.RNNXgb > div > div.a4bIc > input")
            element.send_keys(rows[0])
            element.submit()
            time.sleep(3)
            print "The keyword [" + rows[0] + "] is searched.."
            browser.back()
            time.sleep(3)
            i = i + 1

print "<< Mission Terminated >>"




