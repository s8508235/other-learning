#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
// zig build-exe -ldbus-1 -lpcap -lc  -I ~/replica/libpcap -L ~/replica/libpcap -L /home/bill/replica/dbus/dbus/.libs -I /home/bill/replica/dbus filter-pcap-line.c
// https://stackoverflow.com/questions/681011/getting-the-number-of-packets-in-a-pcap-capture-file
// https://www.ibm.com/docs/en/aix/7.2?topic=pcl-sample-2-capturing-packet-data-saving-it-file-processing-later
int main(int argc, char **argv)
{
    unsigned int packet_counter = 0;
    struct pcap_pkthdr header;
    const u_char *packet;

    if (argc < 4)
    {
        fprintf(stderr, "Usage: %s <pcap> <line-number> <output-pcap-file>\n", argv[0]);
        exit(1);
    }

    char *endptr;
    long long int limit = strtol(argv[2], &endptr, 10);
    if (endptr == argv[2])
    {
        printf("Invalid number: %s\n", argv[2]);
    }
    else if (*endptr)
    {
        printf("Trailing characters after number:%s\n", argv[2]);
    }

    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    handle = pcap_open_offline(argv[1], errbuf);

    pcap_t *pcap;
    pcap_dumper_t *pd; /* pointer to the dump file */
    pcap = pcap_open_dead(DLT_RAW, 65535);
    const char *filename = argv[3];
    if ((pd = pcap_dump_open(pcap, filename)) == NULL)
    {
        /*
                 * Print out error message if pcap_dump_open failed. This will
                 * be the below message followed by the pcap library error text,
                 * obtained by pcap_geterr().
                 */
        fprintf(stderr,
                "Error opening savefile \"%s\" for writing: %s\n",
                filename, pcap_geterr(handle));
        exit(7);
    }

    if (handle == NULL)
    {
        fprintf(stderr, "Couldn't open pcap file %s: %s\n", argv[1], errbuf);
        return (2);
    }

    while (packet = pcap_next(handle, &header))
    {
        packet_counter++;
        if (packet_counter > limit)
        {
            pcap_dump((u_char *)pd, &header, packet);
        }
    }
    pcap_close(handle);
    pcap_dump_close(pd);
    pcap_close(pcap);

    printf("write remaining %lld to %s\n", packet_counter - limit, filename);
    return 0;
}