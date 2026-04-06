<h1>I2C protokol</h1>

<figure class="table">
    <table>
        <thead>
            <tr>
                <th><strong>Signál / pojem</strong></th>
                <th><strong>Význam</strong></th>
                <th><strong>Popis</strong></th>
            </tr>
        </thead>
        <tbody>
            <tr>
                <td>SDA</td>
                <td>Serial Data</td>
                <td>Datová linka pro přenos dat</td>
            </tr>
            <tr>
                <td>SCL</td>
                <td>Serial Clock</td>
                <td>Hodinový signál pro synchronizaci přenosu</td>
            </tr>
            <tr>
                <td>START</td>
                <td>S</td>
                <td>Přechod SDA z 1 na 0 při SCL = 1</td>
            </tr>
            <tr>
                <td>STOP</td>
                <td>P</td>
                <td>Přechod SDA z 0 na 1 při SCL = 1</td>
            </tr>
            <tr>
                <td>ACK</td>
                <td>0</td>
                <td>Příjemce potvrdil přijetí bajtu</td>
            </tr>
            <tr>
                <td>NACK</td>
                <td>1</td>
                <td>Příjemce nepotvrdil přijetí bajtu</td>
            </tr>
            <tr>
                <td>MSB first</td>
                <td>-</td>
                <td>Nejvyšší bit se přenáší jako první</td>
            </tr>
            <tr>
                <td>Open-drain</td>
                <td>-</td>
                <td>Linky jsou taženy do log. 1 pomocí pull-up rezistorů</td>
            </tr>
        </tbody>
    </table>
</figure>

<h2>I2C – průběh komunikace</h2>

<figure class="table">
    <table>
        <thead>
            <tr>
                <th><strong>Krok</strong></th>
                <th><strong>Operace</strong></th>
                <th><strong>Popis</strong></th>
            </tr>
        </thead>
        <tbody>
            <tr><td>1</td><td>START</td><td>Zahájení komunikace</td></tr>
            <tr><td>2</td><td>Adresa + R/W</td><td>Výběr zařízení a směru komunikace</td></tr>
            <tr><td>3</td><td>ACK</td><td>Potvrzení od zařízení</td></tr>
            <tr><td>4</td><td>Data</td><td>Přenos jednoho nebo více bajtů</td></tr>
            <tr><td>5</td><td>ACK / NACK</td><td>Potvrzení po každém přeneseném bajtu</td></tr>
            <tr><td>6</td><td>STOP</td><td>Ukončení komunikace</td></tr>
        </tbody>
    </table>
</figure>

<h2>I2C – základní funkce v programu</h2>

<figure class="table">
    <table>
        <thead>
            <tr>
                <th><strong>Funkce</strong></th>
                <th><strong>Význam</strong></th>
                <th><strong>Popis</strong></th>
            </tr>
        </thead>
        <tbody>
            <tr><td><code>i2c_init()</code></td><td>Inicializace</td><td>Nastaví sběrnici do výchozího stavu</td></tr>
            <tr><td><code>i2c_start()</code></td><td>START</td><td>Vygeneruje start podmínku</td></tr>
            <tr><td><code>i2c_stop()</code></td><td>STOP</td><td>Vygeneruje stop podmínku</td></tr>
            <tr><td><code>i2c_output()</code></td><td>Zápis bajtu</td><td>Odešle jeden bajt a vrátí ACK/NACK</td></tr>
            <tr><td><code>i2c_input()</code></td><td>Čtení bajtu</td><td>Přečte jeden bajt ze sběrnice</td></tr>
            <tr><td><code>i2c_ack()</code></td><td>ACK</td><td>Odešle potvrzení po přijatém bajtu</td></tr>
            <tr><td><code>i2c_nack()</code></td><td>NACK</td><td>Odešle nepřijetí, obvykle po posledním bajtu</td></tr>
        </tbody>
    </table>
</figure>

<h1>SI4735 – I2C příkazy</h1>

<figure class="table">
    <table>
        <thead>
            <tr>
                <th><strong>CMD</strong></th>
                <th><strong>Název</strong></th>
                <th><strong>ARG1</strong></th>
                <th><strong>ARG2</strong></th>
                <th><strong>ARG3</strong></th>
                <th><strong>ARG4</strong></th>
                <th><strong>Popis</strong></th>
            </tr>
        </thead>
        <tbody>
            <tr>
                <td>0x01</td>
                <td>POWER_UP</td>
                <td>MODE</td>
                <td>X</td>
                <td>X</td>
                <td>X</td>
                <td>Zapnutí rádia</td>
            </tr>
            <tr>
                <td>0x10</td>
                <td>GET_REV</td>
                <td>-</td>
                <td>-</td>
                <td>-</td>
                <td>-</td>
                <td>Informace o verzi</td>
            </tr>
            <tr>
                <td>0x12</td>
                <td>SET_PROPERTY</td>
                <td>0x00</td>
                <td>PropHi</td>
                <td>PropLo</td>
                <td>Value</td>
                <td>Nastavení parametru</td>
            </tr>
            <tr>
                <td>0x13</td>
                <td>GET_PROPERTY</td>
                <td>0x00</td>
                <td>PropHi</td>
                <td>PropLo</td>
                <td>-</td>
                <td>Čtení parametru</td>
            </tr>
            <tr>
                <td>0x20</td>
                <td>FM_TUNE_FREQ</td>
                <td>0x00</td>
                <td>FreqHi</td>
                <td>FreqLo</td>
                <td>0x00</td>
                <td>Naladění frekvence</td>
            </tr>
            <tr>
                <td>0x21</td>
                <td>FM_SEEK_START</td>
                <td>ARG</td>
                <td>-</td>
                <td>-</td>
                <td>-</td>
                <td>Automatické ladění stanice</td>
            </tr>
            <tr>
                <td>0x22</td>
                <td>FM_TUNE_STATUS</td>
                <td>0x00</td>
                <td colspan="3">READ</td>
                <td>Stav ladění + frekvence</td>
            </tr>
            <tr>
                <td>0x23</td>
                <td>FM_RSQ_STATUS</td>
                <td>0x00</td>
                <td colspan="3">READ</td>
                <td>Kvalita signálu (RSSI, SNR)</td>
            </tr>
            <tr>
                <td>0x24</td>
                <td>FM_RDS_STATUS</td>
                <td>0x00</td>
                <td colspan="3">READ</td>
                <td>RDS data</td>
            </tr>
        </tbody>
    </table>
</figure>

<h2>PROPERTY (SET_PROPERTY)</h2>

<figure class="table">
    <table>
        <thead>
            <tr>
                <th><strong>Kód</strong></th>
                <th><strong>Název</strong></th>
                <th><strong>Hodnota</strong></th>
                <th><strong>Popis</strong></th>
            </tr>
        </thead>
        <tbody>
            <tr>
                <td>0x4000</td>
                <td>RX_VOLUME</td>
                <td>0–63</td>
                <td>Hlasitost</td>
            </tr>
            <tr>
                <td>0x4001</td>
                <td>RX_HARD_MUTE</td>
                <td>bitové</td>
                <td>Mute</td>
            </tr>
            <tr>
                <td>0x1100</td>
                <td>REFCLK_FREQ</td>
                <td>Hz</td>
                <td>Referenční frekvence</td>
            </tr>
            <tr>
                <td>0x1200</td>
                <td>FM_DEEMPHASIS</td>
                <td>50/75 µs</td>
                <td>Deemphasis</td>
            </tr>
            <tr>
                <td>0x1400</td>
                <td>FM_SEEK_TUNE_SNR_THRESHOLD</td>
                <td>0–127</td>
                <td>Práh SNR</td>
            </tr>
            <tr>
                <td>0x1401</td>
                <td>FM_SEEK_TUNE_RSSI_THRESHOLD</td>
                <td>0–127</td>
                <td>Práh RSSI</td>
            </tr>
        </tbody>
    </table>
</figure>

<h2>FM_TUNE_STATUS – výstup</h2>

<figure class="table">
    <table>
        <thead>
            <tr>
                <th><strong>Byte</strong></th>
                <th><strong>Název</strong></th>
                <th><strong>Popis</strong></th>
            </tr>
        </thead>
        <tbody>
            <tr><td>0</td><td>S1</td><td>Status</td></tr>
            <tr><td>1</td><td>S2</td><td>Status</td></tr>
            <tr><td>2</td><td>FreqHi</td><td>Frekvence (MSB)</td></tr>
            <tr><td>3</td><td>FreqLo</td><td>Frekvence (LSB)</td></tr>
            <tr><td>4</td><td>RSSI</td><td>Síla signálu</td></tr>
            <tr><td>5</td><td>SNR</td><td>Kvalita signálu</td></tr>
            <tr><td>6</td><td>MULT</td><td>Multipath</td></tr>
            <tr><td>7</td><td>CAP</td><td>Kapacita</td></tr>
        </tbody>
    </table>
</figure>

<h2>FM_SEEK_START – význam ARG</h2>

<figure class="table">
    <table>
        <thead>
            <tr>
                <th><strong>Bit</strong></th>
                <th><strong>Název</strong></th>
                <th><strong>Popis</strong></th>
            </tr>
        </thead>
        <tbody>
            <tr><td>3</td><td>SEEKUP</td><td>1 = nahoru, 0 = dolů</td></tr>
            <tr><td>2</td><td>WRAP</td><td>1 = pokračovat přes pásmo</td></tr>
        </tbody>
    </table>
</figure>

<h1>PCF8574 – I2C expander</h1>

<figure class="table">
    <table>
        <thead>
            <tr>
                <th><strong>Položka</strong></th>
                <th><strong>Hodnota</strong></th>
                <th><strong>Popis</strong></th>
            </tr>
        </thead>
        <tbody>
            <tr>
                <td>Základ adresy</td>
                <td>0100 A2 A1 A0 R/W</td>
                <td>7bitová adresa + bit směru komunikace</td>
            </tr>
            <tr>
                <td>Horní část adresy</td>
                <td>0b0100</td>
                <td>Pevná část adresy daná výrobcem</td>
            </tr>
            <tr>
                <td>A2, A1, A0</td>
                <td>0 nebo 1</td>
                <td>Nastavení adresy pomocí přepínačů / propojek</td>
            </tr>
            <tr>
                <td>R/W</td>
                <td>0 = zápis, 1 = čtení</td>
                <td>Směr komunikace</td>
            </tr>
            <tr>
                <td>Datový registr</td>
                <td>8 bitů</td>
                <td>Jediný registr expanderu, přímo odpovídá výstupům P0–P7</td>
            </tr>
        </tbody>
    </table>
</figure>

<h2>PCF8574 – zápis dat</h2>

<figure class="table">
    <table>
        <thead>
            <tr>
                <th><strong>Krok</strong></th>
                <th><strong>Data</strong></th>
                <th><strong>Popis</strong></th>
            </tr>
        </thead>
        <tbody>
            <tr><td>1</td><td>START</td><td>Zahájení komunikace</td></tr>
            <tr><td>2</td><td>Adresa + W</td><td>Adresování expanderu pro zápis</td></tr>
            <tr><td>3</td><td>8bit hodnota</td><td>Data pro LED / výstupy P0–P7</td></tr>
            <tr><td>4</td><td>STOP</td><td>Ukončení komunikace</td></tr>
        </tbody>
    </table>
</figure>

<h2>PCF8574 – příklad adresy</h2>

<figure class="table">
    <table>
        <thead>
            <tr>
                <th><strong>A2</strong></th>
                <th><strong>A1</strong></th>
                <th><strong>A0</strong></th>
                <th><strong>Adresa pro zápis</strong></th>
                <th><strong>Adresa pro čtení</strong></th>
            </tr>
        </thead>
        <tbody>
            <tr><td>0</td><td>0</td><td>0</td><td>0x40</td><td>0x41</td></tr>
            <tr><td>0</td><td>0</td><td>1</td><td>0x42</td><td>0x43</td></tr>
            <tr><td>0</td><td>1</td><td>0</td><td>0x44</td><td>0x45</td></tr>
            <tr><td>0</td><td>1</td><td>1</td><td>0x46</td><td>0x47</td></tr>
            <tr><td>1</td><td>0</td><td>0</td><td>0x48</td><td>0x49</td></tr>
            <tr><td>1</td><td>0</td><td>1</td><td>0x4A</td><td>0x4B</td></tr>
            <tr><td>1</td><td>1</td><td>0</td><td>0x4C</td><td>0x4D</td></tr>
            <tr><td>1</td><td>1</td><td>1</td><td>0x4E</td><td>0x4F</td></tr>
        </tbody>
    </table>
</figure>

