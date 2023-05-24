const map = L.map('map'); 
// Initializes map

map.setView([42.278365, -2.493535], 9); 
// Sets initial coordinates and zoom level

L.tileLayer('https://tile.openstreetmap.org/{z}/{x}/{y}.png', {
    maxZoom: 19,
    attribution: '© OpenStreetMap'
}).addTo(map); 
// Sets map data source and associates with map

let marker, circle, zoomed;



function success() {



    if (marker) {
        map.removeLayer(marker);
        map.removeLayer(circle);
    }

        const lat = updateLat;
      const lng = updateLng;
      console.log(lat);
      console.log(lng);
      marker = L.marker([lat, lng]).addTo(map);
      circle = L.circle([lat, lng]).addTo(map);

    
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

success();


map.on('click', function(e) {
    //alert("Lat, Lon : " + e.latlng.lat + ", " + e.latlng.lng)
    document.getElementById("latitud").value = e.latlng.lat;
    document.getElementById("longitud").value = e.latlng.lng;
});
