import github3
import datetime
from getpass import getuser, getpass
CREDENTIALS_FILE = "/tmp/git_hub_login"

def get_token():
	try:
		with open(CREDENTIALS_FILE, 'r') as fd:
			token = fd.readline().strip()  # Can't hurt to be paranoid
			id = fd.readline().strip()
			fd.close()
	except(IOError):
		return None

def login():
	token = get_token()
	if not token:
		user = raw_input("Github login: ")
		password = ''
		while not password:
			password = getpass('Password for {0}: '.format(user))
			note = "SDLMetricsCollector"
			note_url = "https://github.com/LuxoftAKutsan/SDLMetricsCollector"
			scopes = ['user', 'repo']
			auth = github3.authorize(user, password, scopes, note, note_url)
		with open(CREDENTIALS_FILE, 'w') as fd:
			print(auth)
			fd.write(auth.token + '\n')
			fd.write(auth.id)
			fd.close()
		return login()
	return github3.login(token = token)


def open_pull_request_for_repo(repo):
	now = datetime.datetime.now()
	open_pull_requests = list(repo.pull_requests(state='open'))
	for pull_request in open_pull_requests:
		delta =  now.date() - pull_request.created_at.date()
		print(delta.days)

gh = login()
repo = gh.repository('CustomSDL', 'sdl_panasonic')
open_pull_request_for_repo(repo)
