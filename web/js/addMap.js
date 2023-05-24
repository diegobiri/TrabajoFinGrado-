const map = L.map('map'); 
// Initializes map

map.setView([42.278365, -2.493535], 9); 
// Sets initial coordinates and zoom level

L.tileLayer('https://tile.openstreetmap.org/{z}/{x}/{y}.png', {
    maxZoom: 17,
    attribution: '© OpenStreetMap'
}).addTo(map); 
// Sets map data source and associates with map

let marker, circle, zoomed;

navigator.geolocation.watchPosition(success, error);

function success(pos) {

    //const lat = pos.coords.latitude;
    //const lng = pos.coords.longitude;
    const accuracy = pos.coords.accuracy;

    if (marker) {
        map.removeLayer(marker);
        map.removeLayer(circle);
    }

    if (update) {
      const lat = updateLat;
      const lng = updateLng;
      marker = L.marker([lat, lng]).addTo(map);
      circle = L.circle([lat, lng], { radius: accuracy }).addTo(map);
  }else{
    const lat = 42.278365;
    const lng = -2.493535;
  }
    // Removes any existing marker and circule (new ones about to be set)

    //
    //
    // Adds marker to the map and a circle for accuracy

    if (!zoomed) {
        //zoomed = map.fitBounds(circle.getBounds()); 
    }
    // Set zoom to boundaries of accuracy circle

    map.setView([lat, lng]);
    // Set map focus to current user position

}

function error(err) {

    if (err.code === 1) {
        alert("Please allow geolocation access");
    } else {
        alert("Cannot get current location");
    }

}

map.on('click', function(e) {
    //alert("Lat, Lon : " + e.latlng.lat + ", " + e.latlng.lng)
    document.getElementById("latitud").value = e.latlng.lat;
    document.getElementById("longitud").value = e.latlng.lng;
});