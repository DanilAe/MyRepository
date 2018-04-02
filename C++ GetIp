#include <iostream>
#include <Windns.h> 
using namespace std;

int main()
{
 WSADATA wsa_Data;
 int wsa_ReturnCode = WSAStartup(0x101, &wsa_Data);
 gethostname(hostName, 256); 
 PDNS_RECORD pDnsRecord; 
 DNS_STATUS statsus = DnsQuery(hostName, DNS_TYPE_A, DNS_QUERY_STANDARD, NULL, &pDnsRecord, NULL); 
 IN_ADDR ipaddr; 
 ipaddr.S_un.S_addr = (pDnsRecord->Data.A.IpAddress); 
 printf("The IP address of the host %s is %s \n", hostName, inet_ntoa(ipaddr)); 
 DnsRecordListFree(&pDnsRecord, DnsFreeRecordList);
 return 0;
}
