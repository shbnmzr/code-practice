import threading
import time
import urllib.request

semaphore = threading.Semaphore(3)


def process(url):
    with semaphore:
        print(f'Start process {semaphore}')
        response = urllib.request.urlopen(url)
        data = response.read()
        print(f'Finish process {semaphore}')


def main():
    threads = []
    urls = [
        'https://www.ietf.org/rfc/rfc791.txt',
        'https://www.ietf.org/rfc/rfc792.txt',
        'https://www.ietf.org/rfc/rfc793.txt',
        'https://www.ietf.org/rfc/rfc794.txt',
        'https://www.ietf.org/rfc/rfc795.txt',
    ]

    for url in urls:
        thread = threading.Thread(target=process, args=(url,))
        threads.append(thread)
        thread.start()

    for thread in threads:
        thread.join()


if __name__=='__main__':
    main()
