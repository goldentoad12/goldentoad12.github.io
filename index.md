--- 
layout: single
classes: wide
header:
  image: /images/header.jpg
  show_overlay_excerpt: true
  excerpt: "My goal is to turn environmental data into actionable insight for climate resilience and sustainable systems."
feature_row:
  - image_path: /images/arduino.jpg
    alt: "Arduino"
    title: "Arduino"
    excerpt: "This is some sample content that goes here with **Markdown** formatting."
 - image_path: /images/gis.jpg
    alt: "ArcGIS"
    title: "ArcGIS"
    excerpt: "This is some sample content that goes here with **Markdown** formatting."
--- 

<div class="home-layout">

  <div class="main-content">
    <h1>Welcome!</h1>
    <p>This site will contain the following, an about me, my GIS and Arduino projects, my current academic publications, and an up to date resume. Use the navigation bar at the top of the screen to view everything. </p>
    <!-- whatever your current homepage content is -->
  </div>

  <aside class="sidebar">
    {% include recent-projects.html %}
  </aside>

</div>

{% include feature_row %}
