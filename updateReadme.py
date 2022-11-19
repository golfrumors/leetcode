import requests
import re
import marko
from bs4 import BeautifulSoup

# Get the HTML from the website and store it in a variable

username = input("Enter your leetcode username: ")

URL = "https://leetcode-stat-api.herokuapp.com/%s/" % username
page = requests.get(URL)

soup = BeautifulSoup(page.content, 'html.parser')

# Find the elements in which we're interested

# Find the n of problems solved in the difficulty easy
easy = soup.find('div', style="margin:20px; margin-bottom:2px; margin-top:0px;")

# Find the n of problems solved in the other two difficulties since they have the same style tags

restProblems = soup.find_all('div', style="margin:20px; margin-bottom:2px;")

# Find the number of easy problems & number of solved easy
nEasy = easy.text
nEasy = nEasy.split("/",1)[1]
nEasy = int(nEasy)

solvedEasy = easy.text
solvedEasy = solvedEasy.split(" ")[1]
solvedEasy = solvedEasy.split("/")[0]
solvedEasy = solvedEasy.lstrip()
solvedEasy = int(solvedEasy)

# Find the number of medium problems & number of solved medium
nMedium = restProblems[0].text
nMedium = nMedium.split("/",1)[1]
nMedium = int(nMedium)

solvedMedium = restProblems[0].text
solvedMedium = solvedMedium.split(":")[1]
solvedMedium = solvedMedium.split("/")[0]
solvedMedium = solvedMedium.lstrip()
solvedMedium = int(solvedMedium)

# Find the number of hard problems & number of solved hard
nHard = restProblems[1].text
nHard = nHard.split("/",1)[1]
nHard = int(nHard)

solvedHard = restProblems[1].text
solvedHard = solvedHard.split(":")[1]
solvedHard = solvedHard.split("/")[0]
solvedHard = solvedHard.lstrip()
solvedHard = int(solvedHard)

# Writing the results out into a file

total = nEasy + nMedium + nHard
totalSovled = solvedEasy + solvedMedium + solvedHard

totalSolvedStr = "<code>{0:04d}/%s</code>".format(totalSovled) % total
easySolvedStr = "<code>Easy {0:03d}/%s</code>".format(solvedEasy) % nEasy
mediumSolvedStr = "<code>Medium {0:04d}/%s</code>".format(solvedMedium) % nMedium
hardSolvedStr = "<code>Hard {0:03d}/%s</code>".format(solvedHard) % nHard

# Regex to find the total number of problems solved over the total number of problems, the easy problems solved over the total number of easy problems, etc.

patternTotal = re.compile(r"<[a-zA-Z]+>[0-9]+/[0-9]+</[a-zA-Z]+>", re.IGNORECASE)
patternEasy = re.compile(r"<[a-zA-Z]+>Easy [0-9]+/[0-9]+</[a-zA-Z]+>", re.IGNORECASE)
patternMedium = re.compile(r"<[a-zA-Z]+>Medium [0-9]+/[0-9]+</[a-zA-Z]+>", re.IGNORECASE)
patternHard = re.compile(r"<[a-zA-Z]+>Hard [0-9]+/[0-9]+</[a-zA-Z]+>", re.IGNORECASE)


# convert markdown file to text
fileData = marko.convert(open("README.md").read())

# replace the total number of problems solved over the total number of problems
r1 = re.findall(patternTotal, fileData)
text_after = re.sub(patternTotal, totalSolvedStr, fileData)

# do the same for easy, medium, and hard
r2 = re.findall(patternEasy, text_after)
text_after = re.sub(patternEasy, easySolvedStr, text_after)

r3 = re.findall(patternMedium, text_after)
text_after = re.sub(patternMedium, mediumSolvedStr, text_after)

r4 = re.findall(patternHard, text_after)
text_after = re.sub(patternHard, hardSolvedStr, text_after)

print(text_after)

# Write the results to the README.md file
with open("README.md", "w") as f:
    f.write(text_after)